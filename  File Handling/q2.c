#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 4096

// Function to convert text to upper case
void convertToUpper(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

// Function to convert text to lower case
void convertToLower(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

// Function to convert text to sentence case
void convertToSentenceCase(char *str) {
    int capitalize = 1;

    while (*str) {
        if (capitalize && isalpha((unsigned char)*str)) {
            *str = toupper((unsigned char)*str);
            capitalize = 0;
        } else {
            *str = tolower((unsigned char)*str);
        }

        if (*str == '.' || *str == '?' || *str == '!') {
            capitalize = 1;
        }

        str++;
    }
}

// Function to copy file contents based on the case option
void copyFileWithCaseOption(FILE *sourceFile, FILE *targetFile, int caseOption) {
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        if (caseOption == 'u') {
            convertToUpper(buffer);
        } else if (caseOption == 'l') {
            convertToLower(buffer);
        } else if (caseOption == 's') {
            convertToSentenceCase(buffer);
        }

        fwrite(buffer, 1, bytesRead, targetFile);
    }
}

int main(int argc, char *argv[]) {
    FILE *sourceFile, *targetFile;
    char sourcePath[100], targetPath[100];
    int caseOption = 0;

    if (argc < 3) {
        printf("Insufficient arguments. Usage: ./cp [-u/-l/-s] source_file target_file\n");
        return 1;
    }

    caseOption = argv[1][1];

    printf("Enter the path of the source file: ");
    scanf("%s", sourcePath);

    printf("Enter the path of the target file: ");
    scanf("%s", targetPath);

    // Open the source file for reading
    sourceFile = fopen(sourcePath, "rb");
    if (sourceFile == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    // Open the target file for writing
    targetFile = fopen(targetPath, "wb");
    if (targetFile == NULL) {
        printf("Failed to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy the contents of the source file to the target file with the specified case option
    copyFileWithCaseOption(sourceFile, targetFile, caseOption);

    // Close the files
    fclose(sourceFile);
    fclose(targetFile);

    printf("File copied successfully.\n");

    return 0;
}
