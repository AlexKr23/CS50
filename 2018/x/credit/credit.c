#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    long long cc_number;
    cc_number = get_long_long("Card number please: ");
    int cc = 0;
    int cc_one = 0;
    long long c_n = cc_number;
    while (c_n > 0)
    {
        // double every other digit starting w/ 2nd to last
        // then sum the individual digits of these products
        int sum = ((c_n % 100) - (c_n % 10)) / 10;
        if (sum < 5)
        {
            cc += sum * 2;
        }
        else
        {
            cc += ((sum * 2) % 10) + 1;
        }
        //printf ("%i\n", cc);
        //sum every other digital starting from one
        int sum_one = (c_n % 10);
        cc_one += sum_one;
        //printf ("%i\n", cc_one);
        c_n = floor(c_n / 100);
    }
    //printf("%i\n", cc);
    //printf("%i\n", cc_one);
    //printf("%i\n", cc + cc_one);
    // check to see if the CC number is in the appropriate range
    if ((cc + cc_one) % 10 == 0)
    {
        //printf("%lli\n", cc_number);
        if ((cc_number >= 340000000000000 && cc_number < 350000000000000) || (cc_number >= 370000000000000 && cc_number < 380000000000000))
        {
            printf("AMEX\n");
        }
        else if (cc_number >= 5100000000000000 && cc_number < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        else if ((cc_number >= 4000000000000 && cc_number < 5000000000000) || (cc_number >= 4000000000000000
                 && cc_number < 5000000000000000))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
