#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);
    // cycle for rows
    for (int i = 0; i < height; i++)
    {
        //cycle inside cycle for spaces
        for (int k = 0; k < height - 1 - i; k++)
        {
            printf(" ");
        }
        //cycle inside cycle for hashes
        for (int m = 0; m < i + 1; m++)
        {
            printf("#");
        }
        //spaces between two pyramids
        printf("   ");
        //cycle for 2nd pyramid
        for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
