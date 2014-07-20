#include <stdio.h>
#include <stdlib.h>

#define SWAP(r,s)  do{int t=r; r=s; s=t; } while(0)
 
void siftDown( int *input, int start, int end)
{
    int root = start;
    while ( root*2+1 < end ) {
        int child = 2*root + 1;
        if ((child + 1 < end) && (input[child] < input[child+1]) ) {
            child += 1;
        }
        if (input[root] < input[child]) {
            SWAP( input[child], input[root] );
            root = child;
        } else {
            return;
        }
    }
}

void heap_sort( int *input, int N)
{
    int start, end;
    for (start = (N-2)/2; start >=0; start--) {
        siftDown( input, start, N);
    }
    for (end=N-1; end > 0; end--) {
        SWAP(input[end],input[0]);
        siftDown(input, 0, end);
    }
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

    //heap sort
    heap_sort(input, N);
    
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