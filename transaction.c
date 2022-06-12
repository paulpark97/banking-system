#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "transaction.h"

void deposit(int account_number)
{
    int deposit_input = 0;
    int current_balance = 0;
    int sum = 0, counter = 0;
    printf("How much would you like to deposit? ");
    scanf("%d",&deposit_input);

    char filename[100] = "account_info.txt";
    char temp_filename[100] = "temp.txt";

    FILE* fp = fopen(filename,"r");
    
    int current_account_number = 0;
    char current_account_numb_string[99] = "";

    while(current_account_number != account_number)
    {
        fscanf(fp,"%s",current_account_numb_string);
        current_account_number = atoi(current_account_numb_string);
        counter++;
    }
    fgets(current_account_numb_string, 20,fp);
    fgets(current_account_numb_string, 20,fp);
    fgets(current_account_numb_string, 20,fp);
    fgets(current_account_numb_string, 20,fp);
    fgets(current_account_numb_string, 20,fp);
    counter+=4;
    
    current_balance = atoi(current_account_numb_string);
    
    sum = current_balance + deposit_input;
    char sum_string[100] = "";
    sprintf(sum_string,"%d",sum);
    strcat(sum_string,"\n");
    fclose(fp);

    FILE *file, *temp;
    int current_line = 1;
    file = fopen(filename, "r");
    temp = fopen(temp_filename, "w");

    char buffer[100] = "";
    bool keep_reading = true;
    do
    {
        fgets(buffer, 100, file);
        if (feof(file))
        {
            keep_reading = false;
        }
        else if(counter == current_line)
        {
            fputs(sum_string, temp);
        }
        else
        {
            fputs(buffer, temp);
        }
        current_line++;
    } while (keep_reading);
    
    fclose(file);
    fclose(temp);

    remove(filename);
    rename(temp_filename, filename);
    
}