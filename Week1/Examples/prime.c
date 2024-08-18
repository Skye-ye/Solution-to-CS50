#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int number, i, p, a;
    p = 1;
    number = get_int("Please enter a number\n");
    a = (int)(sqrt(number));
    if (number == 1)
    {
        p = 0;
    }
    for (i = 2; i < a; i++)
    {
        if (number%i == 0)
        p = 0;
    }
    if (p == 1)
    {
        printf("It's a prime number\n");
    }
    else
    {
        printf("It's not a prime number\n");
    }
}