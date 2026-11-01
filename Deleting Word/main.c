#include <stdio.h>
#include <stdbool.h>

int main()
{
    char sentence[200];
    char word[50];

    printf("Enter a sentence: ");
    gets(sentence);
    printf("Enter the word to delete: ");
    gets(word);
    
    // Getting lengths..
    int word_len;
    for(word_len = 0; word[word_len] != '\0'; word_len++){}
    
    // Detection And Deletion..
    int i = 0;
    while(sentence[i] != '\0')
    {
        bool match = true;
        for(int j = 0; j < word_len; j++)
            if(sentence[i + j] != word[j])
            {
                match = false;
                break;
            }

        if (match)
        {
            bool HasPrev = (i == 0 || sentence[i - 1] == ' ');
            bool HasNext = (sentence[i + word_len] == '\0' || sentence[i + word_len] == ' ');

            if(HasPrev && HasNext)
            {
                int k = i;
                for(k = i; sentence[k + word_len] != '\0'; k++)
                    sentence[k] = sentence[k + word_len];
                sentence[k] = '\0';
                continue;
            }}
        i++;
    }

    printf("Modified sentence: %s\n", sentence);
    return 0;
}
