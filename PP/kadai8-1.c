#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0

void binary_search(int input[], int N, int target)
{
    int i, left = 0, mid, right = N,found_target = NO;

    while (left <= right) {
        mid = (left + right) / 2;
        if (input[mid] == target) {
            found_target = YES;
            break;
        } else if (input[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if( found_target == YES){
        printf(" %d is at %d\n.",target,mid);
    } else {
        printf(" %d is not found.\n",target);
    }
}

int main(void)
{
    //declaration
    FILE *fp;
    int i = 0, *input,N=0,target;
    char fname[100], s[100];
    
    //open file
    printf("Please input the file name:");
    scanf("%s",fname);
    fp = fopen(fname,"r");
    if (fp == NULL){
        printf("Can't open the file:%s\n",fname);
        exit(EXIT_FAILURE);
    }
    
    //read file
    if ((input = (int *)malloc(sizeof(int)*10000001)) == NULL) {
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

    printf("Please input number:");
    scanf("%d", &target);

    //binary search
    binary_search(input, N, target);
    
    free(input);
    return 0;
}

