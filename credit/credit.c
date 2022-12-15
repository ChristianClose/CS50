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
    long divisor = 10;
    int firstDigit;
    int firstTwoDigits;

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

    while(temp){
        temp /= 10;
        numOfDigits++;
    }

    for(int i = 0; i < numOfDigits - 2; i++)
    {
        divisor *= 10;
    }

    firstDigit = number / divisor;
    firstTwoDigits = number / (divisor / 10);

    if (sum % 10 == 0){
        if (firstDigit == 4 && (numOfDigits == 13 || numOfDigits == 16))
        {
            printf("VISA\n");
        }
        else if ((firstTwoDigits == 34 || firstTwoDigits == 37) && numOfDigits == 15)
        {
            printf("AMERICAN EXPRESS\n");
        }
        else if ((firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54 || firstTwoDigits == 55) && numOfDigits == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }



}

