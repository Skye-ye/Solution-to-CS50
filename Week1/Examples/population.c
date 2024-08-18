#include <stdio.h>
#include <cs50.h>
int main()
{
    int start_size, end_size, year;
    float a;
    do 
    {
        start_size = get_int("Enter the start size");
    }
    while (start_size < 1);
    do
    {
        end_size = get_int("Enter the end size");
    } while (end_size <= start_size);
    a = start_size;
    for (year = 0; a < end_size; year++)
    {
        a = a*13/12;
    }
    printf("It tooks %i year\n", year);
}