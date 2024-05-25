#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source_file, *destination_file;
    char source_filename[] = "source.txt";
    char destination_filename[] = "destination.txt";
    char ch;

    // Open source file for reading
    source_file = fopen(source_filename, "r");
    if (source_file == NULL) {
        printf("Error opening source file!\n");
        return 1;
    }

    // Open destination file for writing
    destination_file = fopen(destination_filename, "w");
    if (destination_file == NULL) {
        printf("Error opening destination file!\n");
        fclose(source_file);
        return 1;
    }

    // Copy content from source to destination
    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, destination_file);
    }

    // Close files
    fclose(source_file);
    fclose(destination_file);

    printf("File copied successfully!\n");

    return 0;
}

