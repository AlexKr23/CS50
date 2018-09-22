#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//c = hash 50bEGa5oaIHik
int main(int argc, string argv[])
{
    char a[6]; //создаем char "a" шестибайтовый, т.к. у нас пароль состоит только из 5 символов + символ окончания строки
    a[5] = 0; // последнему байту присваиваем значение 0
    if (argc != 2) //program should run with only 2 arguments
    {
        printf("usage : ./crack hash \n");
        return 1;
    }
    else
    {
        char salt[3]; //создаем char для "соли"
        strcpy(salt,
               ""); // копируем в салт пустоту, т.к. в С эта область уже может быть занята
        string hash = argv[1]; //преобразуем аргумент(хэш) в строку
        strncpy(salt, hash,
                2); // копирую в соль только 2 байта из строки хэша, чтобы выцепить "соль"
        string L = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; // строка с алфавитом
        for (int i = 0; L[i] != 0; i++) //cycle for fisrt letter only
        {
            a[0] = L[i];
            string c = crypt(a, salt);
            if ((strcmp(c, hash)) == 0) //сравнение исходного хэша и результата криптования
            {
                printf("Password is %s\n", a);
                return 0;
            }
        }
        for (int i = 0; L[i] != 0; i++) //cycle for fisrt and second letter only
        {
            for (int j = 0; L[j] != 0; j++)
            {
                a[0] = L[i];
                a[1] = L[j];
                string c = crypt(a, salt);
                if ((strcmp(c, hash)) == 0) //сравнение исходного хэша и результата криптования
                {
                    printf("Password is %s\n", a);
                    return 0;
                }
            }
        }
        for (int i = 0; L[i] != 0; i++) //cycle for fisrt, second and third letter only
        {
            for (int j = 0; L[j] != 0; j++)
            {
                for (int k = 0; L[k] != 0; k++)
                {
                    a[0] = L[i];
                    a[1] = L[j];
                    a[2] = L[k];
                    string c = crypt(a, salt);
                    if ((strcmp(c, hash)) == 0) //сравнение исходного хэша и результата криптования
                    {
                        printf("Password is %s\n", a);
                        return 0;
                    }
                }
            }
        }
        for (int i = 0; L[i] != 0; i++) //cycle for fisrt, second, third and forth letter only
        {
            for (int j = 0; L[j] != 0; j++)
            {
                for (int k = 0; L[k] != 0; k++)
                {
                    for (int l = 0; L[l] != 0; l++)
                    {
                        a[0] = L[i];
                        a[1] = L[j];
                        a[2] = L[k];
                        a[3] = L[l];
                        string c = crypt(a, salt);
                        if ((strcmp(c, hash)) == 0) //сравнение исходного хэша и результата криптования
                        {
                            printf("Password is %s\n", a);
                            return 0;
                        }
                    }
                }
            }
        }
        for (int i = 0; L[i] != 0; i++) //cycle for fisrt, second, third and forth letter only
        {
            for (int j = 0; L[j] != 0; j++)
            {
                for (int k = 0; L[k] != 0; k++)
                {
                    for (int l = 0; L[l] != 0; l++)
                    {
                        for (int m = 0; L[m] != 0; m++)
                        {
                            a[0] = L[i];
                            a[1] = L[j];
                            a[2] = L[k];
                            a[3] = L[l];
                            a[4] = L[m];
                            string c = crypt(a, salt);
                            if ((strcmp(c, hash)) == 0) //сравнение исходного хэша и результата криптования
                            {
                                printf("Password is %s\n", a);
                                return 0;
                            }
                        }
                    }
                }
            }
        }

    }
}
