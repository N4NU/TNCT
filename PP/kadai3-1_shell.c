#include <stdio.h>
#include <stdlib.h>

void shell (int N, int h, int input[])
{
	int next,i,j;
	for(i=h;i<N;i++){
		next=input[i];
		for(j=i;j>=h&&input[j-h]>next;j-=h){
			input[j]=input[j-h];
		}
		input[j]=next;
	}
}

int main ()
{
	//declaration
	FILE *fp;
	const int N=100;
	int i=0,j,input[100],h;
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
	
	//shell sort
	for (h=1;h<N;h=3*h+1);
	h=(h-1)/3;
	while(h>=1){
		shell(N,h,input);
		h=h/3;
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