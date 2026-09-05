// To create a function that converts strings to integers..
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int atoi(char string[]);

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf(".\\main [Number..]");
        return 1;
    }

    printf("%d", atoi(argv[1]));
    return 0;
}

int atoi(char string[])
{
    // Base Case
    if(strlen(string) == 0)
    {
        return 0;
    }

    // Recursive Case
    int n = string[strlen(string) - 1] - '0';
    string[strlen(string) - 1] = '\0';
    return atoi(string) * 10 + n;
}