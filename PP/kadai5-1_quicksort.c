#include <stdio.h>
#include <stdlib.h>

void quick_sort (int *input, int n) {
    if (n < 2) return;
    int pivot = *input;
    int *left = input;
    int *right = input + n - 1;
    int tmp;
    while (left <= right) {
        if (*left < pivot) {
            left++;
            continue;
        }
        if (*right > pivot) {
            right--;
            continue;
        }
        tmp = *left;
        *left++ = *right;
        *right-- = tmp;
    }
    quick_sort(input, right - input + 1);
    quick_sort(left, input + n - left);
}
 
int main () {

    //declaration
    FILE *fp;
    int i = 0, *input,N=0;
    char fname[100], s[100];
    
    //open file
    printf("Please input the file name:");
    scanf("%s",&fname);
    fp = fopen(fname,"r");
    if (fp == NULL){
        printf("Can't open the file:%s\n",fname);
        exit(EXIT_FAILURE);
    }
    
    //read file
    if ((input = malloc(sizeof(int)*10000001)) == NULL) {
        printf("Can't reserve memory when execute malloc.\n");
        exit(EXIT_FAILURE);
    }
    while(fgets(s,100,fp)!=NULL){
        *input = atoi(s);
        input++;
        N++;
    }
    fclose(fp);
    input=input-N;

    //quick sort
    quick_sort(input, N);
    
    //output
    i=0;
    while(i!=N){
        printf("\n%d",*(input+i));
        i++;
    }
    printf("\n");
    
    free(input);
    return 0;
}
