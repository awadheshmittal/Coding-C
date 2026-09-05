/*
Implement a program in C that recreates the pyramid:

    #  #
   ##  ##
  ###  ###
 ####  ####

Allow the user to decide just how tall the pyramids should be by
first prompting them for a positive int between 1 and 8, inclusive
*/

#include <stdio.h>

int main()
{
    int row, space, hash;
    int height = 0;

    do
    {
        printf("Enter the height of the pyramid from 1-8: ");
        scanf("%d", &height);
        printf("\n");
    }
    while(height > 8 || height <= 0);


    for(row = 1; row <= height; row++)
    {
        // drawing a pyramid roughly, spaces + hashes in each row equal height (width)
        for(space = 1; space <= height - row; space++)
        {
            printf(" ");
        }

        // hashes in any row equal the exact row no.
        for(hash = 1; hash <= row; hash++)
        {
            printf("#");
        }

        printf("  ");

        for(hash = 1; hash <= row; hash++)
        {
            printf("#");
        }

        printf("\n");
    }
    
    return 0;
}