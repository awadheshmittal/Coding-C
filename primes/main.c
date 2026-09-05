#include <stdio.h>
#include <math.h>

int main()
{
    int n, composite = 0, prime = 0;

    do
    {
        printf("Enter the number(s): ");
        scanf("%d", &n);

        if(n <= 0)
        {
            printf("Enter non-negative numbers!\n");
            continue;
        }
        else if(n == 1)
        {
            break;
        }

        int isPrime = 1;
        int divisor = 2;
        while(divisor <= sqrt(n))
        {
            if((n % divisor) == 0)
            {
                isPrime = 0;
                break;
            }
           divisor++; 
        }

        if(isPrime == 1)
        {
            prime++;
        }
        else
        {
            composite++;
        }
    }
    while(n != 1);

    printf("Primes: %d & Composites: %d", prime, composite);
    return 0;
}