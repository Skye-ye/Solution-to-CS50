#include <stdio.h>
#include <cs50.h>
#include <string.h>

float total(int length, int array[]);

int main(void)
{
    const int N = get_int("Number of weeks taking CS50:");
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Week %i HW Hours:", i);
    }
    string choice;
    do
    {
       choice = get_string("Enter T for total hours, A for average hours per week:");
    }
    while (strcmp(choice, "T") != 0 && strcmp(choice, "A") != 0);
    if (strcmp(choice, "T") == 0)
    {
        printf("%f hours\n", total(N, scores));
    }
    else
    {
        printf("%f hours\n", total(N, scores) / N);
    }
}

float total(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++ )
    {
        sum += array[i];
    }
    return sum;
}