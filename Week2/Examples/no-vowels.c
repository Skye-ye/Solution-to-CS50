#include <stdio.h>
#include <cs50.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    else
    {
        printf("%s\n", replace(argv[1]));
        return 0;
    }
}

string replace(string word)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] == 'a')
        {
            word[i] = '6';
        }
        else if (word[i] == 'e')
        {
            word[i] = '3';
        }
        else if (word[i] == 'i')
        {
            word[i] = '1';
        }
        else if (word[i] == 'o')
        {
            word[i] = '0';
        }
    }
    return word;
}