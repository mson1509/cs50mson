#include <stdio.h>
#include <stdlib.h>

int const block_size = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover <image>\n");
        return 1;
    }
    FILE* ptr = fopen(argv[1], "r");
    if (ptr == NULL)
    {
        printf("File cannot be opened");
        return 1;
    }
    unsigned char buffer[block_size];
    FILE* outptr = NULL;
    while (fread(buffer, block_size, 1, ptr) == block_size)
    {
        int count = 0;
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xF0) == 0xe0)
        {
            sprintf(filename, "%03i", count)
            count++;
            outptr = fopen(filename, "w");
        }
        if (outptr != NULL)
        {
            fwrite(buffer, block_size, 1, outptr);
        }
    }

}