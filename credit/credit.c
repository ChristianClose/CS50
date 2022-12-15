#include <cs50.h>
#include <stdio.h>

void checkCreditCard(long number);

int main(void)
{
    long creditCardNum = get_long("Number: ");
    checkCreditCard(creditCardNum);

}

void checkCreditCard(long number)
{
    long temp = number;
    int sum;

    while(number)
    {
        int lastDigit = temp % 10;
        sum += lastDigit;
        temp /= 100;
    }

    temp = number / 10;

    while(number){
        int lastDigit = temp % 10;
        int doubled = lastDigit * 2;
        sum += (doubled % 10) + (doubled / 10);
    }



}

