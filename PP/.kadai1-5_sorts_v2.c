#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;

void output(int input[],char fn[])
{
	FILE *fp;
	int i;
	i=strlen(fn);
	fn[i-3]='r';
	fn[i-2]='e';
	fn[i-1]='s';
	fn[i]='u';
	fn[i+1]='l';
	fn[i+2]='t';
	fn[i+3]='\0';
	fp=fopen(fn,"w");
	if(fp==NULL){
		printf("Can't open the file:%s\n",fn);
		return ;
	}
	
	i=0;
	while(i!=N){
		fprintf(fp,"%d\n",input[i]);
		i++;
	}
	fclose(fp);
}

void bubble(int input[],char fn[],int n,int N)
{
	//declaration
	int i=0,j,tmp;
	
	//bubble sort
	if (n==1){
		for(i=N-1;0<i;i--){
			for(j=0;j<i;j++){
				if(input[j]>input[j+1]){
					tmp=input[j+1];
					input[j+1]=input[j];
					input[j]=tmp;
				}
			}
		}
	} else if(n==2){
		for(i=N-1;0<i;i--){
			for(j=0;j<i;j++){
				if(input[j]<input[j+1]){
					tmp=input[j+1];
					input[j+1]=input[j];
					input[j]=tmp;
				}
			}
		}
	} else return;
	
	output(input,fn);
}

void select(int input[],char fn[],int n)
{
	int i,j,min,tmp;
	
	if (n==1){
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
	} else if (n==2){
		for(i=0;i<N;i++){
			min=i;
			for(j=i+1;j<N;j++){
				if (input[j]>input[min]){
					min=j;
				}
			}
			tmp=input[i];
			input[i]=input[min];
			input[min]=tmp;
		}
	} else return;
	
	output(input,fn);
}

void insertion(int input[],char fn[],int n)
{
	int i,j,next;
	
	if (n==1){
		for(i=1;i<N;i++){
			next=input[i];
				for(j=i;j>=1&&input[j-1]>next;j--){
				input[j]=input[j-1];
			}
			input[j]=next;
		}
	} else if (n==2){
		for(i=1;i<N;i++){
			next=input[i];
				for(j=i;j>=1&&input[j-1]<next;j--){
				input[j]=input[j-1];
			}
			input[j]=next;
		}
	} else return;
	
	output(input,fn);
}

int main ()
{
	//declaration
	FILE *fp;
	int i=0,j,*input,n,p;
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
	input=(int *)malloc(sizeof(int)*1000);
	while(fgets(s,100,fp)!=NULL){
		input[i]=atoi(s);
		i++;
		if(i!=0&&i%999==0){
			input=(int *)realloc(input,sizeof(int)*(i+1001));
		}
	}
	
	N=sizeof(input)/sizeof(input[0]);
	
	printf("| Ascending order--1   Descending order--2 |\n");
	scanf("%d",&n);
	
	printf("| Bubble--1   Select--2   Insertion--3   Cancel--0 |\n");
	scanf("%d",&p);
	switch(p) {
	   case 1: bubble(input,fname,n);    break;
	   case 2: select(input,fname,n);    break;
	   case 3: insertion(input,fname,n); break;
	   case 0: return 0;
	}
	
	fclose(fp);
	return 0;
}