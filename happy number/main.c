/* Accept an array of numbers..
A happy number is a positive integer that eventually reaches 1 when
you repeatedly replace it with the sum of the squares of its digits */

#include <stdio.h>
#include <stdbool.h>

bool is_happy(int n);

int main()
{
    int n;
    printf("Terms in the array: ");
    scanf("%d", &n);

    int array[n];
    for(int i = 0; i < n; i++)
    {
        printf("Term %d: ", i+1);
        scanf("%d", &array[i]);
    }

    for(int i = 0; i < n; i++)
    {
        if((array[i] > 0) && is_happy(array[i]))
        {
            printf("Term %d ", i+1);
        }
    }
    return 0;
}

bool is_happy(int n)
{
    // Base Case
    if(n == 1)
    {
        return true;
    }
    else if(n == 4)
    {
        return false;
    }

    // Recursive Case
    int sum = 0, digit;
    while(n != 0)
    {
        digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return is_happy(sum);
}
