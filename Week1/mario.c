#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    int target;
    int count = 1;
    int count2 = 1;
    
    do
    {
        height = get_int("Height: ");
    } 
    while (height > 8 || height < 1);
    target = height - 1;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < target; j++)
        {
            printf(" ");
        }
        target--;
        
        for (int k = 0; k < count; k++)
        {
            printf("#");
        }
        count++;
        
        printf("  ");
        
        for (int l = 0; l < count2; l++)
        {
            printf("#");
        }
        printf("\n");
        count2++;
    
    }
    
}
//comment
//comment
//comment
//comment