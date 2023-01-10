#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE * fp;
    fp = fopen("Day3 - input.txt", "r");
    char line[300];

    if (fp == NULL) {
        printf("failed to read \n");
    }
    else {
        printf("successfully read the file \n");
    }

    //generate alphabets and points
    char arr[27];
    char ARR[27];
    int low_num[27] = {0};
    int high_num[27] = {0};
    int i,j,k,found,sum = 0;
    for(i = 0; i < 26; i++)
    {
        arr[i] = 'a'+i;
        ARR[i] = 'A'+i;
        low_num[i] = 1+i;
        high_num[i] = 27+i;
    }
    //end the arrays
    arr[i]='\0';
    ARR[i]='\0';
    low_num[i]='\0';    
    high_num[i]='\0';



    //begin comparison
    while (fgets(line, sizeof(line), fp) != NULL) {
        int len = strlen(line);
        int half_len = len / 2;
        for (i = 0; i < half_len; i++) {
            found = 0;
            for (j = half_len; j < len; j++) {
                if (line[i] == line[j]) {
                    found = 1;
                    printf("%c \n",line[i]);
                    for (k = 0; k < 27; k++) {
                        if (line[i] == arr[k]) {
                            sum += low_num[k];
                        }
                        else if (line[i] == ARR[k]) {
                            sum += high_num[k];
                        }
                    }
                    if (found == 1) break;
                }
                if (found == 1) break;
            }
            if (found == 1) break;
        }
    }

    fclose(fp);

    printf("%d",sum);

    return 0;
}