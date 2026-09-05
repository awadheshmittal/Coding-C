#include <stdio.h>

// Luhn's Algorithm
int main()
{
    long long credit, temp, brand, sum1 = 0, sum2 = 0, count = 0;
    printf("Enter credit number: ");
    scanf("%lld", &credit);
    temp = credit;

    while (credit != 0)
    {
        int digit2 = credit % 10;
        sum2 = sum2 + digit2;

        int digit1 = (credit / 10) % 10;
        int doub = digit1 * 2;

        if (doub >= 10)
        {
            sum1 = sum1 + (doub % 10) + (doub / 10);
        }
        else
        {
            sum1 = sum1 + doub;
        }
        credit /= 100;
    }

    if ((sum1 + sum2) % 10 == 0)
    {
        printf("Valid!\n");
        while (temp != 0)
        {
            temp /= 10;
            count++;

            if(temp >= 10 && temp <= 99)
            {
                brand = temp;
            }
        }

        printf("No. of digits: %lld\n", count);

        if ((brand == 34 || brand == 37) && count == 15)
        {
            printf("American Express");
        }
        else if ((brand >= 51 && brand <= 55) && count == 16)
        {
            printf("MasterCard");
        }
        else
        {
            brand /= 10;
            if (brand == 4 && (count == 13 || count == 16))
            {
                printf("Visa");
            }
            else
            {
                printf("Unrecognised Brand!");
            }
        }
    }
    else 
    {
        printf("Invalid!");
    }

    return 0;
}