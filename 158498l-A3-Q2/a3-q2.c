/*
*   File:       a3-q1.c
*   Author:     Xirui Liu 158498l@acadiau.ca 
*   Date:       2022/3/12
*   Purpose:    get the number and character from user
*               and print out four graph 
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char user_char;
    int user_int, i, recorder, space_recorder, check, check2 = 0;
    printf("please input a character\n");
    while(check != 1)
    {
        check = scanf("%c", &user_char);
        while(getchar() != '\n')
        {
            ;
        }
        if(check != 1)
        {
            fprintf(stderr, "wrong input, try again\n");
        }
    }
    
    printf("please input a number\n");
    while(check2 != 1)
    {
        check2 = scanf("%d", &user_int);
        while(getchar() != '\n')
        {
            ;
        }
        if(check2 != 1)
        {
            fprintf(stderr, "wrong input, try again\n");
        }
    }

    printf("\n");

    //first shape
    for(i = user_int; i > 0; i--)
    {
        recorder = i;
        while(recorder != 0)
        {
            printf("%c", user_char);
            recorder--;
        }
        printf("\n");
    }

    //second shape
    for(i = 1; i < user_int+1; i++)
    {
        recorder = i;
        space_recorder = user_int - i;
        while(space_recorder != 0)
        {
            printf(" ");
            space_recorder--;
        }
        while(recorder != 0 )
        {
            printf("%c", user_char);
            recorder--;
        }
        printf("\n");
    }

    printf("\n");

    //third shape
    int store1, store2, store3, loop_times = 0;
    recorder = user_int;
    space_recorder = 0;
    store1 = recorder;
    store2 = space_recorder;
    store3 = space_recorder;
    while(1)
    {
        if(recorder < 0)
        {
            break;
        }

        while(store2 != 0)
        {
            printf(" ");
            store2--;
        }
        while (store1 != 0)
        {
            printf("%c", user_char);
            store1--;
        }
        while(store3 != 0)
        {
            printf(" ");
            store3--;
        }
        printf("\n");
        
        recorder = recorder - 2;
        store1 = recorder;
        space_recorder++;
        store2 = space_recorder;
        store3 = space_recorder;

        loop_times++;
    }

    printf("\n");
    
    //fourth shape
    //use datas from third shape
    store1 = store1 + 2;
    recorder = store1;
    store2 = space_recorder - 1;
    space_recorder = store2;
    store3 = space_recorder - 1;
    
    store1 = recorder;
    store2 = space_recorder;
    store3 = space_recorder;
    while(1)
    {
        if(recorder > user_int)
        {
            break;
        }

        while(store2 != 0)
        {
            printf(" ");
            store2--;
        }
        while (store1 != 0)
        {
            printf("%c", user_char);
            store1--;
        }
        while(store3 != 0)
        {
            printf(" ");
            store3--;
        }
        printf("\n");
        
        recorder = recorder + 2;
        store1 = recorder;
        space_recorder--;
        store2 = space_recorder;
        store3 = space_recorder;
    }
}