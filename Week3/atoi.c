#include <stdio.h>
#include <cs50.h>
#include <string.h>

int atoi(int length, int number_converted, string number);

int main(void)
{
    string number = get_string("Enter a positive number");
    if (strcmp(number, "-") == 0)
    {
        printf("Invalid Input!\n");
    }
    else
    {
        int length = strlen(number);
        int number_converted = 0;
        printf("%i", atoi(length, number_converted, number));
    }
}

int atoi(int length, int number_converted, string number)
{
    if (length == 0)
    {
        return number_converted;
    }
    atoi(length--, number_converted, number);
    number_converted = number_converted * 10 + (number[length - 1] - '0');
    number[length - 1] = '\0';
}