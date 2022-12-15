#include <cs50.h>
#include <stdio.h>

void checkCreditCard(long number);

int main(void)
{
    int creditCardNum[] = get_int("Number: ");
    printf(creditCardNum);

}

void checkCreditCard(long number)
{
    int sum = number % 10;

}

