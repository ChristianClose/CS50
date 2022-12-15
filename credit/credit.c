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
    long num = number;
    int finalSum = 0;

    while(num){
        num /= 10;
        sum += num;

        num /= 100;
        doubledSum += num * 2;
    }

    finalSum = sum + doubledSum;
    printf("%i\n", finalSum);
    printf("%i\n", sum);
    printf("%i\n", doubledSum);

    if(finalSum % 10 == 0){
        printf("Valid Card\n");
    }


}

