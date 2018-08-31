#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int k = 0;
    int i = 0;
    int n = 0;
    if (argc != 2)
    {
        printf("usage : ./caesar + k \n");
        return 1;
    }
    else
    {
        k = atoi(argv[1]);
        //asking for a text
        string p = get_string("plaintext: ");
        //cipher output
        printf("ciphertext: ");
        //cycle for string length
        for (i = 0, n = strlen(p); i < n; i++)
        {
            //for upper alpa
            if ((isupper(p[i])) && (isalpha(p[i])))
            {
                //if new cipher exceed ASCII code for upper alpa
                //(k % 26) is for when key is higher than 26 (amount of character in english alphabet)
                if ((p[i] + (k % 26)) > 90)
                {
                    printf("%c", ((p[i] + (k % 26)) - 91) + 65);
                }
                else
                {
                    printf("%c", ((p[i] + (k % 26))));
                }
            }
            //for lower alpha
            else if ((islower(p[i])) && (isalpha(p[i])))
            {
                if ((p[i] + (k % 26)) > 122)
                {
                    printf("%c", ((p[i] + (k % 26)) - 123) + 97);
                }
                else
                {
                    printf("%c", ((p[i] + (k % 26))));
                }
            }
            else
            {
                printf("%c", p[i]);
            }
            //eprintf("%i\n", p[i] + k);
        }
        printf("\n");
    }
}
