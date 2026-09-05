#include <stdio.h>

// To learn Recursion..
int collatz(int n)
{
    if(n == 1)
    {
        return 0;
    }
    else if(n % 2 == 0)
    {
        return collatz(n / 2) + 1;
    }
    else
    {
        return collatz(3 * n + 1) + 1;
    }
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("The number of steps it takes is %d", collatz(n));
    return 0;
}