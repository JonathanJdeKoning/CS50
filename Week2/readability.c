#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    float l = 0;
    float w = 1;
    float s = 0;
    string text = get_string("Text: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0)
        {
            l++;
        }
        if (isblank(text[i]) != 0)
        {
            w++;
        }
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            s++;
        }
    }
    if (round(0.0588 * ((l / w) * 100) - 0.296 * ((s / w) * 100) - 15.8) < 1)
    {
        printf("Before Grade 1\n");
    } 
    else if (round(0.0588 * ((l / w) * 100) - 0.296 * ((s / w) * 100) - 15.8) > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(0.0588 * ((l / w) * 100) - 0.296 * ((s / w) * 100) - 15.8));
    }
    
}


