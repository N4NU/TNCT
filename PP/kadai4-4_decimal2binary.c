#include <stdio.h>

int decimal2binary (int n)
{
	if(n==0){
		return 0;
	}else{
		decimal2binary(n/2);
		printf("%d",n%2);
	}
}


int main ()
{
	int n;
	while(n){
		printf("Please input positive integer >> ");
		scanf("%d",&n);
		printf("%d -> ",n);
		decimal2binary(n);
		printf("\n");
	}
}