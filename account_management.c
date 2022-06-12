#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "account_management.h"


void newAccount(char *first_name, char *last_name, int *pin, int *account_number)
{
    int total_balance = 0;
    char current_account_numb[10] = "";
    time_t t;
    srand((unsigned) time(&t));
    *account_number = (rand() % 89999) + 10000;
    
    //Opening file
    FILE* fp = fopen("account_info.txt", "a+");
    //Checking if account number has the same value as previous account numbers
    
    while(!feof(fp))
    {
        fscanf(fp, "%s", current_account_numb);
        if(atoi(current_account_numb) == *account_number)
        {
            rewind(fp);
            *account_number = (rand() % 89999) + 10000;
        }
    }

    
    //Information questions
    printf("What is your first name?\n");
    scanf("%s",first_name);
    printf("What is your last name?\n");
    scanf("%s",last_name);
    printf("Input a 4 digit pin number: ");
    scanf("%d",pin);
    //Checking valid pin number
    while(*pin > 9999 || *pin < 1000)
    {
        printf("Invalid pin, input a 4 digit pin number: ");
        scanf("%d",pin);
    }

    printf("Your account number is %d\n",*account_number);

    //printing information to file
    char account_string[10];
    sprintf(account_string, "%d", *account_number);
    fprintf(fp,"%s\n",account_string);
    char pin_string[6];
    sprintf(pin_string, "%d", *pin);
    fprintf(fp,"%s\n",pin_string);
    fprintf(fp,"%s\n",first_name);
    fprintf(fp,"%s\n",last_name);
    char total_balance_string[99];
    sprintf(total_balance_string, "%d", total_balance);
    fprintf(fp,"%s\n",total_balance_string);
    fclose(fp);
}

void existingAccount(char *first_name, char *last_name, int *pin, int *account_number)
{
    int inputted_account_numb = 0;
    int inputted_pin = 0;
    bool account_bool = false, pin_bool = false;

    printf("Enter your 5 digit account number: ");
    scanf("%d", &inputted_account_numb);
    printf("Enter your 4 digit pin: ");
    scanf("%d", &inputted_pin);

    FILE* fp = fopen("account_info.txt", "a+");
    char current_account_numb[99] = "";
    char current_pin[99] = "";
    
    while(atoi(current_account_numb) != inputted_account_numb && !feof(fp))
    {
        fscanf(fp, "%s", current_account_numb);
        if(atoi(current_account_numb) == inputted_account_numb)
        {
            account_bool = true;
        }
    }

    if(account_bool)
    {
        fscanf(fp, "%s", current_account_numb);
        strcpy(current_pin, current_account_numb);
        
        if(atoi(current_pin) == inputted_pin)
        {
            pin_bool = true;
        }
    }

    if(pin_bool && account_bool)
    {
        printf("\nAccount access granted\n");
        *pin = inputted_pin;
        *account_number = inputted_account_numb;
        fscanf(fp, "%s", first_name);
        fscanf(fp, "%s", last_name);

    }
    else
    {
        printf("Invalid information inputted\n");
    }
    fclose(fp);
}