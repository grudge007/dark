#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>  // For getenv function

#define QUOTE_FILE ".dark.txt"  // File name relative to home directory

int main() {
    // Get the user's home directory
    char *home_dir = getenv("HOME");
    if (home_dir == NULL) {
        perror("Error getting home directory");
        return 1;
    }

    // Combine home directory and file name
    char quote_file_path[512];  // Buffer for full path
    snprintf(quote_file_path, sizeof(quote_file_path), "%s/%s", home_dir, QUOTE_FILE);

    // Seed random number generator
    srand(time(NULL));

    // Open quote file
    FILE *fp = fopen(quote_file_path, "r");
    if (fp == NULL) {
        perror("Error opening quote file");
        return 1;
    }

    // Get number of lines in the file
    int lines = 0;
    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        lines++;
    }
    rewind(fp); // Rewind the file pointer

    // Generate random line number
    int random_line = rand() % lines + 1;

    // Read and display the random quote
    for (int i = 0; i < random_line; i++) {
        if (fgets(line, sizeof(line), fp) == NULL) {
            perror("Error reading quote file");
            fclose(fp);
            return 1;
        }
    }
    printf("%s", line);

    // Close the file
    fclose(fp);

    return 0;
}
