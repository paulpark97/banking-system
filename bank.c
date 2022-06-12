#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "account_management.h"
#include "transaction.h"

int main()
{
    char first_name[99] = "", last_name[99] = "";
    int account_number = 0;
    int pin = 0, account_access = 0;
    char input;

    printf("Welcome to the bank!\nAre you an existing member or would you like to create a new account?\n");
    printf("Input 'e' for existing member or 'n' to create a new account: ");
    scanf(" %c",&input);
    input = tolower(input);
    //making an account
    if(input == 'n')
    {
        newAccount(first_name,last_name, &pin, &account_number);
    }
    //logging into an account
    else if(input == 'e')
    {
        existingAccount(first_name,last_name, &pin, &account_number);
    }
    
    //account accessed
    if(pin != 0 && account_number != 0)
    {
        printf("Welcome %s %s\n",first_name,last_name);
        while(input != 'q')
        {
            printf("\nWhat would you like to do?\n\nPress\n");
            printf("'D' for deposit\n'W' for withdrawal\n'V' to view how much money is in your account\n'Q' to quit\n");
            scanf(" %c",&input);
            input = tolower(input);

            switch(input)
            {
                case 'd' :
                    deposit(account_number);
                    break;
                case 'w' : 
                    withdraw(account_number);
                    break;
                case 'v':
                    viewAmountInBank(account_number);
                    break;

            }
        }
    }
    

    
    return 0;
}