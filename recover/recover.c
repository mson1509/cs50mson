#include <stdio.h>
#include <stdlib.h>

int const sizeof_block = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover <image>\n");
        return 1;
    }
    FILE* ptr = fopen("argv[1]", "r");
    if (ptr == NULL)
    {
        printf("File cannot be opened");
        return 1;
    }
    int* buffer = malloc(sizeof_block);
    fread(buffer, sizeof_block, 1, ptr);
    }

}