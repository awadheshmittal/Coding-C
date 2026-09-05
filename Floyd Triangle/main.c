#include <stdio.h>

//Floyd's Triangle
int main()
{
    int rows;
    printf("Enter number of rows to generate: ");
    scanf("%d", &rows);


    int n = 1;
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            printf("%2d ", n);
            n++;
        }
        printf("\n");
    }

    return 0;
}