#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 256   // Maximum length for file name strings

// Function to safely read a string from stdin
void read_string(char *str, size_t size) {
    if (fgets(str, size, stdin)) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';  // Remove newline character
        }
    }
}

int main() {
    FILE *sourceFile, *destFile;
    unsigned char buffer;
    char sourceName[MAX_STR];
    char destName[MAX_STR];

    printf("Source file name? ");
    read_string(sourceName, MAX_STR);

    sourceFile = fopen(sourceName, "rb");
    if (sourceFile == NULL) {
        printf("Error: Cannot open source file '%s'.\n", sourceName);
        return EXIT_FAILURE;
    }

    printf("Destination file name? ");
    read_string(destName, MAX_STR);

    destFile = fopen(destName, "wb");
    if (destFile == NULL) {
        printf("Error: Cannot create destination file '%s'.\n", destName);
        fclose(sourceFile);
        return EXIT_FAILURE;
    }

    // Copy the first 54 bytes (e.g., BMP header) directly
    for (int i = 0; i < 54; i++) {
        if (fread(&buffer, 1, 1, sourceFile) != 1) break;
        fwrite(&buffer, 1, 1, destFile);
    }

    // Copy and apply XOR (invert colors) for the rest of the file
    while (fread(&buffer, 1, 1, sourceFile) == 1) {
        buffer = 255 ^ buffer;  // Invert bits
        fwrite(&buffer, 1, 1, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);

    printf("File copy with transformation completed successfully!\n");
    return EXIT_SUCCESS;
}
