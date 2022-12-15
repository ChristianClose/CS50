#include <cs50.h>
#include <stdio.h>

void checkCreditCard(long number);

int main(void)
{
    long creditCardNum = get_long("Number: ");

}

void checkCreditCard(long number)
{
    for(int i = sizeof number; i > 0; i-2)
    {
        printf("%i", i);
    }
}

