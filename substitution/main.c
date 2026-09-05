#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Encrypts text using a key entered as a command-line argument
int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        printf("Enter key!");
        return 1;
    }
    if(strlen(argv[1]) != 26)
    {
        printf("Enter Full key!");
        return 2;
    }
    
    int seen[26] = {0}; // Creates and initialises an array to check for duplicates
    for(int i = 0; i < 26; i++)
    {
        if(isalpha(argv[1][i]))
        {
            int index = toupper(argv[1][i]) - 'A'; // Converts letters of key to their index
            if(seen[index] > 0) 
            /* The value will be greater than 0 iff the letter at that index was already
            visited before, since we're incrementing the seen[index] in the loop */
            {
                printf("Key cannot have Duplicates!");
                return 4;
            }
            seen[index]++;
        }
        else
        {
            printf("Enter Alphabetic key!");
            return 3;
        }
    }

    char plaintext[100], ciphertext[100];
    printf("Plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Removes '\n' BUT only if it is there..

    for(int j = 0; j < strlen(plaintext); j++)
    {
        if(isupper(plaintext[j]))
        {
            int index = plaintext[j] - 'A';
            ciphertext[j] = argv[1][index];
        }
        else if(islower(plaintext[j]))
        {
            int index = plaintext[j] - 'a';
            ciphertext[j] = tolower(argv[1][index]);
        }
        else
        {
            ciphertext[j] = plaintext[j];
        }
    }

    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
