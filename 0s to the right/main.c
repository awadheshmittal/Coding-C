#include <stdio.h>

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int array[n];
    for(int i = 0; i < n; i++)
    {
        printf("E%d: ", i+1);
        scanf("%d", &array[i]);
    }

    int new_array[n];
    for(int i = 0; i < n; i++)
    {
        new_array[i] = 0;
    }

    int idx = 0;
    for(int i = 0; i < n; i++)
    {
        if(array[i] != 0)
        {
            new_array[idx] = array[i];
            idx++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", new_array[i]);
    }
}