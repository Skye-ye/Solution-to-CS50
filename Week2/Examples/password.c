#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

bool check(string word);

int main(void)
{
    do
    {
        string password = get_string("Enter your password:");
        if (check(password))
        {
            printf("Your password is valid!");
            break;
        }
        else
        {
            printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol!\n");
        }
    }
    while (true);
}

bool check(string word)
{
    bool uppercase = 0, lowercase = 0, digit = 0, symbol = 0;
    for (int i = 0; word[i] != '\0'; i++)
    if (isupper(word[i]))
    {
        uppercase = 1;
    }
    else if (islower(word[i]))
    {
        lowercase = 1;
    }
    else if (isdigit(word[i]))
    {
        digit = 1;
    }
    else if (ispunct(word[i]))
    {
        symbol = 1;
    }
    return (uppercase && lowercase && digit && symbol);
}