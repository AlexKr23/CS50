#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    //promt for user
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);
    //conversion to integer
    int cents = round(change * 100);
    int twentyfive = cents / 25;
    //our left
    int left = cents % 25;
    int ten = left / 10;
    //changing our left for each coin
    left = left % 10;
    int five = left / 5;
    left = left % 5;
    int one = left / 1;
    printf("%i\n", twentyfive + ten + five + one);
}
