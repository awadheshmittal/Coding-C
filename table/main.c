#include <stdio.h>

int main()
{
    int k;
    printf("How many terms to generate: ");
    scanf("%d", &k);

    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            printf("%3d ", i*j);
        }
        printf("\n");
    }
    return 0;
}