#include <stdio.h>
#include <stdlib.h>
 
void merge(int * input, int left_start, int left_end, int right_start, int right_end)
{
	int left_length = left_end - left_start;
	int right_length = right_end - right_start;
	int left_half[left_length];
	int right_half[right_length];
	int r = 0;
	int l = 0;
	int i = 0;

	for (i = left_start; i < left_end; i++, l++){
		left_half[l] = input[i];
	}
	for (i = right_start; i < right_end; i++, r++){
		right_half[r] = input[i];
	}
	for ( i = left_start, r = 0, l = 0; l < left_length && r < right_length; i++){
		if ( left_half[l] < right_half[r] ) { 
			input[i] = left_half[l++];
		} else { 
			input[i] = right_half[r++]; 
		}
	}
	for ( ; l < left_length; i++, l++) input[i] = left_half[l];
	for ( ; r < right_length; i++, r++) input[i] = right_half[r];
}
 
void mergesort_r(int left, int right, int * input)
{
	if (right - left <= 1){
		return;
	}
	int left_start  = left;
	int left_end    = (left+right)/2;
	int right_start = left_end;
	int right_end   = right;
	mergesort_r( left_start, left_end, input);
	mergesort_r( right_start, right_end, input);
	merge(input, left_start, left_end, right_start, right_end);
}
 
void merge_sort(int *input, int length)
{
	mergesort_r(0, length, input);
}

int main () 
{
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

    //merge sort
    merge_sort(input, N);
    
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