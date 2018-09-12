#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int i = 0;
    int clen = 0;
    int plen = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    //program should run with only 2 arguments
    if (argc != 2)
    {
        printf("usage : ./vigenere k \n");
        return 1;
    }
    else
    {
        //checking every character for isalpha
        for (j = 0, clen = strlen(argv[1]); j < clen; j++)
        {
            if (!isalpha(argv[1][j]))
            {
                printf("usage : Keyword must be only A-Z and a-z \n");
                return 1;
            }
        }
        {
            string plain = get_string("plaintext: ");
            //printing out ciphertext
            printf("ciphertext: ");
            string key = argv[1];
            //cycle for plaintext code
            for (i = 0, plen = strlen(plain); i < plen; i++)
            {
                //for lower
                if ((isupper(plain[i])) && (isalpha(plain[i])))
                {
                    //iterate for k-th for l-th letter!
                    k = l % clen;
                    if (islower(key[k]))
                    {
                        //converting k-th letter to upper
                        key[k] = toupper(key[k]);
                    }
                    //if new cipher exceed ASCII code for upper alpha
                    if ((plain[i] + (key[k] - 65)) > 90)
                    {
                        printf("%c", ((plain[i] + (key[k] - 65)) - 91) + 65);
                        l++;
                    }
                    else
                    {
                        printf("%c", ((plain[i] + (key[k] - 65))));
                        l++;
                    }
                }
                //for upper
                else if ((islower(plain[i])) && (isalpha(plain[i])))
                {
                    //iterate for k-th for l-th letter!
                    k = l % clen;
                    if (islower(key[k]))
                    {
                        //converting k-th letter to upper
                        key[k] = toupper(key[k]);
                    }
                    //if new cipher exceed ASCII code for lower alpha
                    if ((plain[i] + (key[k] - 65)) > 122)
                    {
                        printf("%c", ((plain[i] + (key[k] - 65)) - 123) + 65);
                        l++;
                    }
                    else
                    {
                        printf("%c", ((plain[i] + (key[k] - 65))));
                        l++;
                    }
                }
                else
                {
                    printf("%c", plain[i]);
                }

            }
            //final \n
            printf("\n");
        }

    }
}
