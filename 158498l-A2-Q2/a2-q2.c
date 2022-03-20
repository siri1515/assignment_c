/*
*   File:       a2-q2.c
*   Author:     Xirui Liu 158498l@acadiau.ca 
*   Date:       2022/2/11
*   Purpose:
                displays a menu on the screen(show 4 options)
                let the user choose an option and ask for input from the user.
                let the first number subtract the second number and output the result.
                
*/

#include <stdio.h>
#include <stdlib.h>

void integer_integer()
{
    int integer_number1, integer_number2, check;
    printf("you choose a, please input two integers seperately\n");
    while(1)
    {
        check = scanf("%d %d", &integer_number1, &integer_number2);
        while(getchar() != '\n')
        {
            ;
        }
        if(check == 2)
        {
            printf("difference is: %d\n", integer_number1 - integer_number2);
            break;
        }
        else
        {
            fprintf(stderr, "wrong input, try again\n");
        }
    }
}

void decimal_decimal()
{
    float decimal_number1, decimal_number2;
    int check;
    printf("you choose b, please input two decimal numbers seperately\n");
    while(1)
    {
        check = scanf(" %f %f", &decimal_number1, &decimal_number2);

        while(getchar() != '\n')
        {
            ;
        }
        if(check == 2)
        {
            printf("difference is: %.2f\n", decimal_number1 - decimal_number2);
            break;
        }
        else
        {
            fprintf(stderr, "wrong input, try again\n");
        }
    }
}

void integer_decimal()
{
    int integer, convert_to_int, check;
    float decimal, convert_to_float;

    printf("you choose c, please input one integer and one decimal number(order matter!)\n");
    while(1)
    {
        check = scanf(" %d %f", &integer, &decimal);
        while(getchar() != '\n')
        {
            ;
        }
        if(check == 2)
        {
            convert_to_float = (float)integer;
            printf("difference is(treat the int as a float): %.2f\n", convert_to_float - decimal);
            convert_to_int = (int)decimal;
            printf("difference is(cast the float to an int): %d\n", integer - convert_to_int);
            break;
        }
        else
        {
            fprintf(stderr, "wrong input, try again\n");
        }
    }
}


int main()
{
    printf("please choose an option to input: \n");
    printf("a enter two integers\n");
    printf("b enter two decimal numbers\n");
    printf("c enter one integer and one decimal number\n");
    printf("d quit\n");
    char user_choice;

    /*int integer_number1, integer_number2, convert_to_int;
    float decimal_number1, decimal_number2, convert_to_float;*/
    while(1)
    {
        scanf(" %c", &user_choice);
        while(getchar() != '\n')
        {
            ;
        }
        if((user_choice == 'a') || (user_choice == 'b') || (user_choice == 'c') || (user_choice == 'd'))
        {
            break;
        }
        else
        {
            fprintf(stderr, "wrong input, try again\n");
        }
    }
    
    switch(user_choice)
    {
        case 'a':
            integer_integer();
            break;
        case 'b':
            decimal_decimal();
            break;
        case 'c':
            integer_decimal();
            break;
        case 'd':
            return EXIT_FAILURE;
            break;
        
    }


    return EXIT_SUCCESS;
}

