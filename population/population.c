#include <cs50.h>
#include <stdio.h>

int prompt_user(int population, char *prompt_string);
int calculate_years(int start_population, int end_population);

int main(void)
{
    const int MINIMUM_POPULATION = 9;
    int start_population = prompt_user(MINIMUM_POPULATION, "Enter the starting population");;
    int end_population = prompt_user(start_population, "Enter the ending population");
    int years = calculate_years(start_population, end_population);
    printf("Years: %d\n", years);
}

int prompt_user(int min_pop, char *prompt_string)
{
    int population;

    do
    {
        printf("%s\n", prompt_string);
        scanf("%d", &population);
    }
    while (population < min_pop);

    return population;
}

int calculate_years(int start_population, int end_population)
{
    int current_population = start_population;
    int births = 0;
    int deaths = 0;
    int years = 0;

    while (current_population < end_population)
    {
        births = current_population / 3;
        deaths = current_population / 4;
        current_population += births - deaths;
        years++;
    }

    return years;
}


