#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function Prototype
int PointsScored(char word[]);

int main()
{
    char words[2][50];
    printf("Enter Player 1's word: ");
    fgets(words[0], sizeof(words[0]), stdin);
    words[0][strlen(words[0]) - 1] = '\0';
    // Removes '\n' from second-last string char behind '\0', even if not there..

    printf("Enter Player 2's word: ");
    fgets(words[1], sizeof(words[1]), stdin);
    words[1][strlen(words[1]) - 1] = '\0';

    int sum1 = PointsScored(words[0]), sum2 = PointsScored(words[1]);

    if(sum1 < sum2)
    {
        printf("Player 2 wins!");
    }
    else if(sum1 > sum2)
    {
        printf("Player 1 wins!");
    }
    else
    {
        printf("Tie!");
    }

    return 0;
}

// Function
int PointsScored(char word[])
{ 
    int sum=0;
    const int score[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    for(int i = 0; word[i] != '\0'; i++)
    {
        if(isalpha(word[i]))
        {
            int index = toupper(word[i]) - 'A';
            sum += score[index];
        }
    }
    return sum;
}