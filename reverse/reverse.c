#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int header_size = 44;

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse <input.wav> <output.wav>\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE* inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Cannot open input file\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header_buffer;
    fread(&header_buffer, header_size, 1, inptr);


    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(header_buffer) == 0)
    {
        printf("Input file is not wav\n");
        return 1;
    }
    // Open output file for writing
    // TODO #5
    FILE* outptr = fopen(argv[2], "w");
    if (outptr == NULL)
    {
        printf("Cannot open output file\n");
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&buffer_header, header_size, 1, outptr);

    // Use get_block_size to calculate size of block
    // TODO #7
    block_size = get_block_size(header_buffer);
    

    // Write reversed audio to file
    // TODO #8
    fclose(inptr);
    fclose(outptr);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int num_channels = header.numChannels * sizeof(WORD);
    int bits_sample = header.bitsPerSample * sizeof(WORD);
    int block_size = num_channels * bitsPerSample;
    return block_size;
}