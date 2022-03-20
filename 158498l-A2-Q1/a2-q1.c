/*
*   File:       a2-q1.c
*   Author:     Xirui Liu 158498l@acadiau.ca 
*   Date:       2022/2/06
*   Purpose:
                Output the number of occurrences of digits, characters, punctuation, 
                "other" characters, and the total count of all characters that occur 
                in the file. (show this in terms of two columns of neatly-formatted data)
                
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "usage: a2-q1 <file_name>");
        return EXIT_FAILURE;
    }
    
    FILE *file_handle;
    file_handle = fopen(argv[1], "r");
    int char_holder = 0, 
        number_of_digit = 0, 
        number_of_character = 0, 
        number_of_punct = 0, 
        number_of_other = 0, 
        total_number = 0;
    
    while((char_holder = fgetc(file_handle)) != EOF)
    {
        if(isdigit(char_holder))
        {
            number_of_digit++;
        }
        else if(isalpha(char_holder))
        {
            number_of_character++;
        }
        else if(ispunct(char_holder))
        {
            number_of_punct = number_of_punct + 1;
        }
        else
        {
            number_of_other++;
        }
    }

    total_number = number_of_digit + number_of_character 
                + number_of_punct + number_of_other;
    
    printf("digits(0-9) %24d\n", number_of_digit);
    printf("characters(upper/lower letter) %5d\n", number_of_character);
    printf("punctuation %24d\n", number_of_punct);
    printf("others(except above) %15d\n", number_of_other);
    printf("total count %24d\n", total_number);
    fclose(file_handle);
    return EXIT_SUCCESS;
}