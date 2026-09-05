#include <stdio.h>
#include <stdlib.h>

int main()
{
    // calculator

    float a = 0;
    float b = 0;
    char operation = '\0';
    float result = 0;

    printf("Enter first number: ");
    scanf("%f", &a);
    
    printf("Enter second number: ");
    scanf("%f", &b);

    printf("Enter which operation to perform: ");
    scanf(" %c", &operation);

    switch(operation)
    {
        case '+':
            result = a+b;
            break;

        case '-':
            result = a-b;
            break;


        case '*':
            result = a*b;
            break;

        case '/':
            if(b != 0)
            {
                result = a/b;
            }
            else
            {
                printf("Division by 0 is invalid!");
                return 2;
            }
            break;

        default:
            printf("Invalid Operation");
            return 1;

    }

    printf("Result: %.2f", result);

    return 0;
}