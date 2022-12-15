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
    int doubledSum = 0;
    int sum = 0;
    long num = 0;
    int finalSum = 0;

    while(number){
        num = number / 10;
        sum += num;

        num = number / 100;
        doubledSum += num * 2;

        break;
    }

    finalSum = sum + doubledSum;

    if(finalSum % 10 == 0){
        printf("Valid Card");
    }


}

