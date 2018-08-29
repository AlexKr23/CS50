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
        for (int m = 0; m < i + 2; m++)
        {
            printf("#");
        }
        printf("\n");
    }
}
