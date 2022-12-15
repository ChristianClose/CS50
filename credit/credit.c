#include <cs50.h>
#include <stdio.h>

void checkCreditCard(long number);
int getFirstCCSum(long number);
int getSecondCCSum(long number);
int getNumOfDigits(long number);
long getDivisor(long number, int numOfDigits);
string getCCProvider(long number, long divisor, int sum, int numOfDigits);

int main(void)
{
    long creditCardNum = get_long("Number: ");
    checkCreditCard(creditCardNum);
}

void checkCreditCard(long number)
{
    int sum = 0;
    int numOfDigits = 0;
    long divisor = 10;
    string provider;

    sum = getFirstCCSum(number);
    sum += getSecondCCSum(number);
    numOfDigits = getNumOfDigits(number);
    divisor = getDivisor(number, numOfDigits);
    provider = getCCProvider(number, divisor, sum, numOfDigits);
    printf("%s", provider);
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

long getDivisor(long number, int numOfDigits)
{
    long divisor = 10;

    for (int i = 0; i < numOfDigits - 2; i++)
    {
        divisor *= 10;
    }

    return divisor;
}

string getCCProvider(long number, long divisor, int sum, int numOfDigits)
{
    int firstDigit = number / divisor;
    int firstTwoDigits = number / (divisor / 10);
    string provider = "";

    if (sum % 10 == 0)
    {
        if (firstDigit == 4 && (numOfDigits == 13 || numOfDigits == 16))
        {
            provider = "VISA\n";
        }
        else if ((firstTwoDigits == 34 || firstTwoDigits == 37) && numOfDigits == 15)
        {
            provider = "AMEX\n";
        }
        else if ((firstTwoDigits > 50 && firstTwoDigits < 56) && numOfDigits == 16)
        {
            provider = "MASTERCARD\n";
        }
    }
    else
    {
        provider = "INVALID\n";
    }

    return provider;
}

