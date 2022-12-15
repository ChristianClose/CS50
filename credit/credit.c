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
    int sum = 0;
    int numOfDigits = 0;
    int divisor = 0;

    while(temp)
    {
        int lastDigit = temp % 10;
        sum += lastDigit;
        temp /= 100;
    }

    temp = number / 10;

    while(temp){
        int lastDigit = temp % 10;
        int doubled = lastDigit * 2;
        sum += (doubled % 10) + (doubled / 10);
        temp /= 100;
    }

    temp = number;

    while(number){
        temp /= 10;
        numOfDigits++;
    }

    if(sum % 10 == 0){
        printf("Valid Card");
    }



}

