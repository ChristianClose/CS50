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
    double divisor = 10;
    double firstDigit;
    double firstTwoDigits;

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

    firstDigit = number / divisor;
    firstTwoDigits = number / (divisor / 10);
    printf("%i\n", sum);
    printf("%i\n", numOfDigits);
    printf("%dd\n", firstDigit);
    printf("%dd\n", firstTwoDigits);

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



}

