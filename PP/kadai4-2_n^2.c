#include <stdio.h>

int factorial (int n)
{
	return n*((n<=1) ? 1 : factorial (n-1));
}


int main ()
{
	int n;
	while(n){
		printf("Please input positive integer >> ");
		scanf("%d",&n);
		printf("%d! = %d\n",n,factorial(n));
	}
}