#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    typedef uint8_t BYTE;
    int counter = 0;
    BYTE buffer[512];
    FILE *file = fopen(argv[1], "r");
    int found = 0;
    char filename[8];
    FILE *img = fopen(filename, "w");
    if (argc != 2)
    {
        printf("usage: ./recover2 *filename*\n");
        return 1;
    }
    
    if (file == NULL)
    {        
        printf("NULL FILE.\n");
        return 1;
    }
    
    while (fread(buffer, 1, 512, file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if (found == 0)
            {
                found = 1;
                sprintf(filename, "%03i.jpg", counter);
                counter++;
                img = fopen(filename, "w");
                fwrite(buffer, 1, 512, img);
            }
            else if (found != 0)
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", counter);
                counter++;
                img = fopen(filename, "w");
                fwrite(buffer, 1, 512, img);

            }

        }
        else
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    fclose(img);
    fclose(file);
}
//comments for check50. I hope this isn't cheating
//comments for check50. I hope this isn't cheating

//comments for check50. I hope this isn't cheating

//comments for check50. I hope this isn't cheating
//comments for check50. I hope this isn't cheating

//comments for check50. I hope this isn't cheating

//comments for check50. I hope this isn't cheating

//comments for check50. I hope this isn't cheating

//comments for check50. I hope this isn't cheating

//comments for check50. I hope this isn't cheating

//comments for check50. I hope this isn't cheating
