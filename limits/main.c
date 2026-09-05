#include <stdio.h>
#include <math.h>

// Generating primes between 2 given limits
int main()
{
    int L, U, n;
    printf("Enter upper and lower limits: ");
    scanf("%d %d", &U, &L);
    n = L;

    printf("The primes between the specified limits are: ");
    while((n >= L) && (n <= U))
    {
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

        if(isPrime == 1 && (n > 1))
        {
            printf("%d, ", n);
        }

        n++;
    }
    return 0;
}