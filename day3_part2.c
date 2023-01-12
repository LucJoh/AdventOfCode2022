#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    fp = fopen("Day3 - input.txt", "r");
    char line[100];
    if (fp == NULL) {
        printf("Failed to read file.\n");
        return 1;
    } else {
        printf("Successfully read file.\n");
    }

    // Generate alphabets and points
    char arr[27];
    char ARR[27];
    int low_num[27] = {0};
    int high_num[27] = {0};
    int i, j, k, found, sum = 0;
    for (i = 0; i < 26; i++) {
        arr[i] = 'a' + i;
        ARR[i] = 'A' + i;
        low_num[i] = 1 + i;
        high_num[i] = 27 + i;
    }
    // End the arrays
    arr[i] = '\0';
    ARR[i] = '\0';
    low_num[i] = '\0';
    high_num[i] = '\0';

    // Begin comparison
    char three_rows[3][100];
    i = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        found = 0;
        strcpy(three_rows[i], line);
        int len = strlen(three_rows[0]);
        if (i == 2) {
            for (j = 0; j < len; j++) {
                if ((strchr(three_rows[1], three_rows[0][j]) != NULL) &&
                    (strchr(three_rows[2], three_rows[0][j]) != NULL)) {
                    for (k = 0; k < 27; k++) {
                        if (three_rows[0][j] == arr[k]) {
                            sum += low_num[k];
                            found = 1;
                        } else if (three_rows[0][j] == ARR[k]) {
                            found = 1;
                            sum += high_num[k];
                        }
                        if (found == 1) break;
                    }
                }
            }
            i = 0;
        } else {
            i++;
        }
    }
    fclose(fp);
    printf("Sum: %d\n", sum);
    return 0;
}
