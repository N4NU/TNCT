#include <stdio.h>
#include <stdlib.h>

int main ()
{
	//declaration
	FILE *fp;
	const int N=100;
	int i=0,j,input[100],tmp,sw=0;
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
	
	//Cocktail sort
	while(sw==0){
		for(i=0;i<N/2;i++){
			for(j=i;j<N-i-1;j++){
				if(input[j]>input[j+1]){
					tmp=input[j];
					input[j]=input[j+1];
					input[j+1]=tmp;
					sw=1;
				}
			}
			for(j=N-2-i;j>i;j--){
				if(input[j]<input[j-1]){
					tmp=input[j];
					input[j]=input[j-1];
					input[j-1]=tmp;
					sw=1;
				}
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
	
	fclose(fp);
	return 0;
}