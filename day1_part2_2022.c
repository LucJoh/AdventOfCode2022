#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE * fp; 
    fp = fopen("Day1 - input.txt", "r");
    char line[300];
    long long int arr[1000] = {0};
    int i = 0;
    long long int sum = 0;

    if (fp == NULL) {
        printf("failed to read \n");
    }
    else {
        printf("successfully read the file \n");
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        int num = atoi(line);
        if (num == 0) {
            arr[i] = sum;
            //printf("%d \n",arr[i]);
            i++;
            sum = 0;
        }
        else {
            sum = (sum + num);
        }
    } 

    fclose(fp);

    arr[i] = sum;              //last sum, no 0 after
    //printf("%d \n",arr[i]);

    int arraySize = sizeof(arr)/sizeof(arr[0]);
    int max, max2, max3;
    max3 = max = max2 = arr[0];
    arr[1000] = 0;

   for(int i = 0; i < arraySize; i++){
      if (arr[i] > max){
         max3 = max2;
         max2 = max;
         max = arr[i];
      }
      else if (arr[i] > max2){
         max3 = max2;
         max2 = arr[i];
      }
      else if (arr[i] > max3)
         max3 = arr[i];
   }

    int max_sum = max + max2 + max3;

    printf("%d",max_sum);

   return 0; 
} 