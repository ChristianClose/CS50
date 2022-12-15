#include <cs50.h>
#include <stdio.h>

void checkCreditCard(long number);
int getfirstCCSum(long number);
int getSecondCCSum(long number);
int getNumOfDigits(long number);
long getDivisor(long number);
string getCCProvidor(long number, long divisor, int sum, int numOfDigits);

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
    string providor;

    // while(temp)
    // {
    //     int lastDigit = temp % 10;
    //     sum += lastDigit;
    //     temp /= 100;
    // }

    sum = getFirstCCSum(number);
    sum += getSecondCCSum(number);
    numOfDigits = getNumOfDigits(number);
    divisor = getDivisor(number);
    providor = getCCProvidor(number, divisor, sum, numOfDigits);

    // temp = number / 10;

    // while (temp)
    // {
    //     int lastDigit = temp % 10;
    //     int doubled = lastDigit * 2;
    //     sum += (doubled % 10) + (doubled / 10);
    //     temp /= 100;
    // }

    // temp = number;

    // while (temp)
    // {
    //     temp /= 10;
    //     numOfDigits++;
    // }

    // for (int i = 0; i < numOfDigits - 2; i++)
    // {
    //     divisor *= 10;
    // }

    // firstDigit = number / divisor;
    // firstTwoDigits = number / (divisor / 10);

    // if (sum % 10 == 0)
    // {
    //     if (firstDigit == 4 && (numOfDigits == 13 || numOfDigits == 16))
    //     {
    //         printf("VISA\n");
    //     }
    //     else if ((firstTwoDigits == 34 || firstTwoDigits == 37) && numOfDigits == 15)
    //     {
    //         printf("AMEX\n");
    //     }
    //     else if ((firstTwoDigits > 50 && firstTwoDigits < 56) && numOfDigits == 16)
    //     {
    //         printf("MASTERCARD\n");
    //     }
    //     else
    //     {
    //         printf("INVALID\n");
    //     }
    // }
    // else
    // {
    //     printf("INVALID\n");
    // }

}

int getFirstCCSum(long number)
{
    long temp = number;
    int sum = 0;

    while(temp)
    {
        int lastDigit = temp % 10;
        sum += lastDigit;
        temp /= 100;
    }

    return sum;
}

int getSecondCCSum(long number)
{
    long temp = number / 10;
    int sum = 0;

    while (temp)
    {
        int lastDigit = temp % 10;
        int doubled = lastDigit * 2;
        sum += (doubled % 10) + (doubled / 10);
        temp /= 100;
    }

    return sum;
}

int getNumOfDigits(long number)
{
    long temp = number;
    int numOfDigits = 0;

    while (temp)
    {
        temp /= 10;
        numOfDigits++;
    }

    return numOfDigits;

}

long getDivisor(long number)
{
    long divisor = 10;

    for (int i = 0; i < numOfDigits - 2; i++)
    {
        divisor *= 10;
    }

    return divisor;
}

string getCCProvidor(long number, long divisor, int sum, int numOfDigits)
{
    int firstDigit = number / divisor;
    int firstTwoDigits = number / (divisor / 10);

    if (sum % 10 == 0)
    {
        if (firstDigit == 4 && (numOfDigits == 13 || numOfDigits == 16))
        {
            printf("VISA\n");
        }
        else if ((firstTwoDigits == 34 || firstTwoDigits == 37) && numOfDigits == 15)
        {
            printf("AMEX\n");
        }
        else if ((firstTwoDigits > 50 && firstTwoDigits < 56) && numOfDigits == 16)
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

