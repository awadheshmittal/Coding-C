#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()
{
    int words = 1, sentences = 0, letters = 0;
    char text[1024];
    printf("Enter text: \n");
    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0';

    for(int i = 0; text[i] != '\0'; i++)
    {
        if(isspace(text[i]))
        {
            words++;
        }
        if(isalpha(text[i]))
        {
            letters++;
        }
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    
    if(round(index) < 1)
    {
        printf("Before Grade 1");
    }
    else if(round(index) >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %.0f", round(index));
    }

    return 0;

}