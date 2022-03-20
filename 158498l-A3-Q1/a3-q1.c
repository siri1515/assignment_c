/*
*   File:       a3-q1.c
*   Author:     Xirui Liu 158498l@acadiau.ca 
*   Date:       2022/3/12
*   Purpose:
                write 3 function(remove comments of file, 
                remove empty line of file, add number to 
                each line of file). ask choice from user and 
                implement the function, if user input 4, exit.
                
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

//  remove all type of comments
//  basically there're two type of comments 
//  //  and  /* */
//  so we can find / and /, /* and */
//  and delete contents between them
void remove_comment(FILE* file_handle, FILE *file_handle2)
{
    char char_holder;                     
    while((char_holder = fgetc(file_handle)) != EOF)
    {
        /* Print whatever it scanned */
        #ifdef DEBUG
        printf("%c", char_holder);
        #endif //DEBUG

        if (char_holder == '/')
        {
            char_holder = fgetc(file_handle);
            if (char_holder == '/')
            {
                #ifdef DEBUG
                printf("c1 find\n");
                #endif

                while (fgetc(file_handle) != '\n')
                {
                    ;
                }  

            }
            else if (char_holder == '*')
            {
                #ifdef DEBUG 
                printf("c2 find");
                #endif 

                while(1){
                    char_holder = fgetc(file_handle);
                    while (char_holder != '*')
                    {
                        char_holder = fgetc(file_handle);
                    }
                    char_holder = fgetc(file_handle);
                    if (char_holder == '/')
                    {
                        break;
                    }
                    else
                    {
                        fseek(file_handle, -1, SEEK_CUR);
                    }
                }

            }
        }
        else
            fputc(char_holder,file_handle2);
        
    }
}

void remove_line(FILE *file_handle, FILE *file_handle2){
    char buffer[1024];
    int total=0, space=0;
    /* scan each line, and only output that line to file unless it's not empty line.  */
    while (fscanf(file_handle, "%[^\n]%*c", buffer) != EOF) {
        /* Check if this line is blank. */
        total = 0; space = 0;
        for (size_t i = 0; i < strlen(buffer); i++){
            if (isspace(buffer[i])){
                space++;
            }
            total++;
        }

        if (space != total){
            fprintf(file_handle2, "%s\n", buffer);
        }
    }
}

void add_number(FILE *file_handle, FILE *file_handle2)
{
    /*
    char char_holder;
    int line_recorder = 1;
    fputc('/', file_handle2);
    fputc('*', file_handle2);
    fprintf(file_handle2, "%d", line_recorder);
    fputc('*', file_handle2);
    fputc('/', file_handle2);
    
    while((char_holder = fgetc(file_handle)) != EOF)
    {
        if(char_holder == '\n')
        {
            fputc(char_holder,file_handle2);
            line_recorder = line_recorder + 1;
            fputc('/', file_handle2);
            fputc('*', file_handle2);
            fprintf(file_handle2, "%d", line_recorder);
            fputc('*', file_handle2);
            fputc('/', file_handle2);
        }
        else
        {
            fputc(char_holder,file_handle2);
        }

    }
    */


    int line_num = 1;
    char char_holder;

    fprintf(file_handle2, "%d\t", line_num);
    while((char_holder = fgetc(file_handle)) != EOF){
        if (char_holder == '\n'){
            fputc(char_holder, file_handle2);
            line_num++;
            fprintf(file_handle2, "%d\t", line_num);
        }
        else{
            fputc(char_holder, file_handle2);
        }
    }

}

FILE** transfer_file(char name[], FILE *fp1, FILE *fp2){
    fclose(fp1);
    fclose(fp2);
    remove(name);
    rename("newfile.c", name);
    FILE **fpc = malloc(2*sizeof(FILE*));
    fpc[0] = fopen(name, "r");
    fpc[1] = fopen("newfile.c", "w+");
    return fpc;
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "usage: a3-q1 <file_name>");
        return EXIT_FAILURE;
    }
    
    FILE *file_handle = fopen(argv[1], "r");                  //user file, for read
    FILE *file_handle2 = fopen("newfile.c", "w+");            //create a new file to save the content we wanted
    FILE **fpc;

    int user_choice, check = 0;

    while(user_choice != 4)
    {
        printf("please choose a option\n");
        printf("1. Remove the comments from the file.\n");
        printf("2. Remove the blank lines from the file.\n");
        printf("3. Put line numbers in the file.\n");
        printf("4. Quit.\n");
        check = scanf("%d", &user_choice);
        while(check != 1)
        {
            while(getchar() != '\n')
            {
                ;
            }
            if(check != 1)
            {
                fprintf(stderr, "wrong input, try again\n");
                check = scanf("%d", &user_choice);
            }
        }

        while(1)
        {
            
            if(user_choice == 1)
            {
                remove_comment(file_handle, file_handle2);
                fpc = transfer_file(argv[1], file_handle, file_handle2);
                file_handle = fpc[0];
                file_handle2 = fpc[1];
                break;
            }
            else if(user_choice == 2)
            {
                remove_line(file_handle, file_handle2);
                fpc = transfer_file(argv[1], file_handle, file_handle2);
                file_handle = fpc[0];
                file_handle2 = fpc[1];
                break;
            }
            else if(user_choice == 3)
            {
                add_number(file_handle, file_handle2);
                fpc = transfer_file(argv[1], file_handle, file_handle2);
                file_handle = fpc[0];
                file_handle2 = fpc[1];
                break;
            }
            else if(user_choice == 4)
            {
                remove("newfile.c");
                return EXIT_FAILURE;
                break;
            }            
            else
            {
                fprintf(stderr, "wrong input, please try again\n");
                scanf("%d", &user_choice);
                while(getchar() != '\n')
                {
                    ;
                }
            }
        }

    }
    if(fclose(file_handle) == EOF)
    {
        fprintf(stderr, "file close failed.\n");
    }

    if(fclose(file_handle2) == EOF)
    {
        fprintf(stderr, "file close failed.\n");
    }
    return EXIT_SUCCESS;
}
