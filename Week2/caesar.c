#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./cs key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (islower(text[i]))
        {
            int c = text[i];
            c -= 97;
            c += key;
            c %= 26;
            c += 97;
            printf("%c", c);
        }
        else if (isupper(text[i]))
        {
            int c = text[i];
            c -= 65;
            c += key;
            c %= 26;
            c += 65;
            printf("%c", c);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}