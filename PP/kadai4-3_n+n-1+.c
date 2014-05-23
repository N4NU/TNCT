#include <stdio.h>

int sum (int n)
{
	return n+((n<=1) ? 0 : sum (n-1));
}


int main ()
{
	int n;
	while(n){
		printf("Please input positive integer >> ");
		scanf("%d",&n);
		printf("%d\n",sum(n));
	}
}