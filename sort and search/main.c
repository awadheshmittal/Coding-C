#include <stdio.h>

int main()
{
    // Array Input
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++)
    {
        printf("E%d: ", i+1);
        scanf("%d", &array[i]);
    }

    // Selection Sort: 
    /* i for array[i] to be replaced by a smaller element
       j loops thru to find smallest element in unsorted loop
       k is the index found for smallest element yet */
    for(int i = 0; i < n-1; i++)
    {
        int k = i;
        for(int j = i+1; j < n; j++)
        {
            if(array[j] < array[k])
                k = j;
        }
        int temp = array[i];
        array[i] = array[k];
        array[k] = temp;
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    // Asking For Searching Number
    printf("\nWhich number to search for? ");
    int search;
    scanf("%d", &search);

    // Binary Search:
    int idx1 = 0, idx2 = n - 1, idx;
    while(true)
    {
        if(idx1 > idx2)
        {
            printf("Number is not in the array!");
            break;
        }

        idx = (idx1 + idx2) / 2;
        if(array[idx] > search)
            idx2 = idx - 1;
        else if(array[idx] < search)
            idx1 = idx + 1;
        else
        {
            printf("Index of the number is: %d", idx);
            break;
        }    
    }
}