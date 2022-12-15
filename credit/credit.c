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
    int sum = 0;
    int num = number;
    int num2 = number / 10;
    int finalSum = 0;
    int doubledSum = num2 *2;

    while(number){
        num = number % 10;
        sum += num;

        num2 %=  10;
        doubledSum += num2 * 2;

        number /= 100;
    }

    finalSum = sum + doubledSum;
    printf("%i\n", finalSum);
    printf("%i\n", sum);
    printf("%i\n", doubledSum);

    if(finalSum % 10 == 0){
        printf("Valid Card\n");
    }


}

