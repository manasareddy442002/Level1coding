#include <stdio.h>

#define BUFFER_SIZE 4026

int main() {
    FILE *sourceFile, *targetFile;
    char sourcePath[100], targetPath[100];
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

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

    // Copy the contents of the source file to the target file
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, targetFile);
    }

    // Close the files
    fclose(sourceFile);
    fclose(targetFile);

    printf("File copied successfully.\n");

    return 0;
}
