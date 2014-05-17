#include <stdio.h>

int main ()
{
	//declaration
	const int N=10;
	int i=0,j,input[10],min,tmp;
	
	//input
	while(i!=N){
		scanf("%d",&input[i]);
		i++;
	}
	
	//Select sort
	for(i=0;i<N;i++){
		min=i;
		for(j=i+1;j<N;j++){
			if (input[j]<input[min]){
				min=j;
			}
		}
		tmp=input[i];
		input[i]=input[min];
		input[min]=tmp;
	}
	
	//output
	i=0;
	while(i!=N){
		printf("\n%d",input[i]);
		i++;
	}
	printf("\n");
	
	return 0;
}