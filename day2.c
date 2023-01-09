#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A - X Y Z
// B - X Y Z
// C - X Y Z

int main() {

    FILE * fp;
    fp = fopen("Day2 - input.txt", "r");
    char line[300];
    int points = 0;

    if (fp == NULL) {
        printf("failed to read \n");
    }
    else {
        printf("successfully read the file \n");
    }

    while (fgets(line, sizeof(line), fp) != NULL) {

        // Remove the trailing newline character from the line
        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "A X") == 0) {
            points += 4;
        }
        else if (strcmp(line, "A Y") == 0) {
            points += 8;
        }
        else if (strcmp(line, "A Z") == 0) {
            points += 3;
        }
        else if (strcmp(line, "B X") == 0) {
            points += 1;
        }
        else if (strcmp(line, "B Y") == 0) {
            points += 5;
        }
        else if (strcmp(line, "B Z") == 0) {
            points += 9;
        }
        else if (strcmp(line, "C X") == 0) {
            points += 7;
        }
        else if (strcmp(line, "C Y") == 0) {
            points += 2;
        }
        else if (strcmp(line, "C Z") == 0) {
            points += 6;
        }
    }

    fclose(fp);

    printf("%d",points);

    return 0;
}