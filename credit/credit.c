#include <cs50.h>
#include <stdio.h>

void checkCreditCard(long number);

int main(void)
{
    long creditCardNum = get_long("Number: ");
    printf(creditCardNum);

}

void checkCreditCard(long number)
{
    int sum = number % 10;
    
}

