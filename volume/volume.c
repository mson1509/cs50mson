// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t header[HEADER_SIZE];
    for (int i = 0; i < HEADER_SIZE; i++)
    {
        fread(header, sizeof(uint8_t), HEADER_SIZE, input);
        fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);
    }

    // TODO: Read samples from input file and write updated data to output file

    uint16_t sequence = malloc(num_samples * sizeof(int16_t))
    fread(sequence, sizeof(int16_t), num_samples, input);
    fwrite(sequence, sizeof(int16_t), num_samples, output);


    // Close files
    fclose(input);
    fclose(output);
}
