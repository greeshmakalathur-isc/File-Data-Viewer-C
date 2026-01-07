#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[100];
    char keyword[50];
    char line[500];
    int lineNumber = 0;
    int found = 0;

    // Input file name
    printf("Enter file name to search: ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("❌ File not found!\n");
        return 1;
    }

    // Input keyword
    printf("Enter word to search: ");
    scanf("%s", keyword);

    printf("\n🔍 Searching for '%s'...\n\n", keyword);

    // Read file line by line
    while (fgets(line, sizeof(line), file)) {
        lineNumber++;

        // Check if keyword exists in line
        if (strstr(line, keyword) != NULL) {
            printf("✅ Found at line %d: %s", lineNumber, line);
            found = 1;
        }
    }

    if (!found) {
        printf("❌ Word not found in file.\n");
    }

    fclose(file);
    return 0;
}
