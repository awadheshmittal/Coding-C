#include <stdio.h>

// Function to reverse a number

int main()
{
    int num, remainder, reverse;
    reverse=0;
    int temp;

    printf("Enter number:\n");
    scanf("%d",&num);
    temp = num;

    while(num != 0)
    {
        remainder = num % 10;
        reverse = reverse * 10 + remainder;
        num /= 10;
    }

    printf("The reversed number is: %d\n", reverse);

    if(reverse == temp) 
    {
        printf("The number is a palindrome!");
    }
    else
    {
        printf("The number is not a palindrome!");

    }
    return 0;
}