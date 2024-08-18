#include <stdio.h>
#include <cs50.h>

float calculator(float bill, float percent);

int main (void)
{
    float bill, percent;
    bill = get_float("Bill before tax and tip:\n");
    percent = get_float("Sale Tax Percent:\n");
    calculator(bill, percent);
    percent = get_float("Tip percent:\n");
    calculator(bill, percent);
    printf("You will owe %f each\n", bill);
}

float calculator(float bill, float percent)
{
    bill = bill * (1 + percent/100);
    return bill;
}
