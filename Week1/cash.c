#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    float raw_change;
    do
    {
        raw_change = get_float("change owed: ");
    }
    while (raw_change < 0);

    int coins = 0;
    float step1 = raw_change * 100;
    int change = round(step1);
    
    while (change >= 25)
    {
        change -= 25;
        coins++;
    }
    while (change >= 10)
    {
        change -= 10;
        coins++;
    }
    while (change >= 5)
    {
        change -= 5;
        coins++;
    }
    while (change >= 1)
    {
        change -= 1;
        coins++;
    }
    
    printf("%i\n", coins);
}