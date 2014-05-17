#include <stdio.h>

int main ()
{
	//declaration
	const int N=10;
	int i=0,j,input[10],tmp;
	
	//input
	while(i!=N){
		scanf("%d",&input[i]);
		i++;
	}
	
	//bubble sort
	for(i=N-1;0<i;i--){
		for(j=0;j<i;j++){
			if(input[j]>input[j+1]){
				tmp=input[j+1];
				input[j+1]=input[j];
				input[j]=tmp;
			}
		}
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