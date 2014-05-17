#include <stdio.h>
#include <stdlib.h>

int main ()
{
	//declaration
	FILE *fp;
	const int N=100;
	int i=0,j,input[100],next;
	char fname[100],s[100];
	
	//open file
	printf("Please input the file name:");
	scanf("%s",&fname);
	fp=fopen(fname,"r");
	if(fp==NULL){
		printf("Can't open the file:%s\n",fname);
		return -1;
	}
	
	//read file
	while(fgets(s,100,fp)!=NULL){
		input[i]=atoi(s);
		i++;
	}
	
	//Insertion sort
	for(i=1;i<N;i++){
		next=input[i];
			for(j=i;j>=1&&input[j-1]>next;j--){
			input[j]=input[j-1];
		}
		input[j]=next;
	}
	
	//output
	i=0;
	while(i!=N){
		printf("\n%d",input[i]);
		i++;
	}
	printf("\n");
	
	fclose(fp);
	return 0;
}