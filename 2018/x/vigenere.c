#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //int key = 0;
    int i = 0;
    int clen = 0;
    int plen = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    if (argc != 2) //program should run with only 2 arguments
    {
        printf("usage : ./vigenere k \n");
        return 1;
    }
    else
    {
        for (j = 0, clen = strlen(argv[1]); j < clen; j++) //checking every character for isalpha
        {
            if (!isalpha(argv[1][j]))
            {
                printf("usage : Keyword must be only A-Z and a-z \n");
                return 1;
            }
        }
        {
            string plain = get_string("plaintext: ");
            printf("ciphertext: ");
            string key = argv[1];
            for (i = 0, plen = strlen(plain); i < plen; i++) //cycle for plaintext code
            {

                if ((isupper(plain[i])) && (isalpha(plain[i])))
                {
                    k = l % clen;
                    if (islower(key[k]))
                    {
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
                else if ((islower(plain[i])) && (isalpha(plain[i])))
                {
                    k = l % clen;
                    if (islower(key[k]))
                    {
                        key[k] = toupper(key[k]);
                    }
                    //if new cipher exceed ASCII code for lower alpha
                    if ((plain[i] + (key[k] - 65)) > 122)
                    {
                        printf("%c", ((plain[i] + (key[k] - 65)) - 123) + 97);
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
            printf("\n");
        }

    }
}
