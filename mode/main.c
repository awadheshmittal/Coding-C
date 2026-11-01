#include <stdio.h>
#include <stdbool.h>

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

    int max = array[0];
    for(int i = 0; i < n; i++)
    {
        if(max < array[i])
            max = array[i];
    }

    // Here, count[i] will basically function like "count of i"
    // Here, "max + 1" because if largest element is 0; sizeof(count) needs to be 1..
    int count[max + 1];
    for(int i = 0; i <= max; i++)
        count[i] = 0;
    for(int i = 0; i < n; i++)
        count[array[i]]++;
    
    int highest_count = count[0];
    for(int i = 0; i <= max; i++)
    {
        if(highest_count <= count[i])
            highest_count = count[i];
    }
    for(int i = 0; i <= max; i++)
    {
        if(count[i] == highest_count)
            printf("%d ", i);
    }
}

// Keeping this part commented for later reflection if ever needed..
    // for(int i = 0; i < n; i++)
    //     count[i] = 0;
    // int idx = 0;
    // for(int i = 0; i < n; i++)
    // {
    //     bool counted = false;
    //     for(int j = 0; j < i; j++)
    //     {
    //         if(array[i] == array[j])
    //         {
    //             counted = true;
    //             break;
    //         }
    //     }
    //     if(!counted)
    //     {
    //         for(int j = i + 1; j < n; j++)
    //         {
    //             if(array[j] == array[i])
    //                 count[idx]++;
    //         }
    //         idx++;
    //     }
    // }