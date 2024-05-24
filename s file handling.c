#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[] = "example.txt";
    char buffer[100];

    // Open file for writing
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write data to the file
    fprintf(file, "Hello, this is a test!\n");
    fprintf(file, "This is line 2 of the file.\n");
    fclose(file);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read data from the file and print to stdout
    printf("Contents of %s:\n", filename);
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);

    // Append data to the file
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file, "Appending new line to the file.\n");
    fclose(file);

    // Open file again for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read and print contents after appending
    printf("\nContents of %s after appending:\n", filename);
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);

    return 0;
}




File handling functions in C facilitate reading from and writing to files.
fopen(): Opens a file with a specified mode (e.g., "r" for reading, "w" for writing).
fclose(): Closes a file.
fprintf(), fscanf(): Write and read formatted data from files.
fputc(), fgetc(): Write and read characters from files.
fgets(), fputs(): Read and write strings from/to files.
File handling functions are essential for tasks such as reading configuration files, logging data, and storing information persistently.