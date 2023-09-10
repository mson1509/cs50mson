#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int const header_size = 44;
int const bits_per_byte = 8;

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
    long header_end = ftell(inptr);

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
    fwrite(&header_buffer, header_size, 1, outptr);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header_buffer);

    // Write reversed audio to file
    // TODO #8
    BYTE block_buffer[block_size];
    long stop_reverse;
    fseek(inptr, -block_size, SEEK_END);
    do
    {
        fread(block_buffer, block_size, 1, inptr);
        fwrite(block_buffer, block_size, 1, outptr);
        fseek(inptr, - 2 * block_size, SEEK_CUR);
        stop_reverse = ftell(inptr);
    }
    while (stop_reverse >= header_end);
    fclose(inptr);
    fclose(outptr);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int num_channels = header.numChannels;
    int bytes_sample = header.bitsPerSample / bits_per_byte;
    int block_size = num_channels * bytes_sample;
    return block_size;
}