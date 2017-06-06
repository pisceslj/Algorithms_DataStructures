#include <stdio.h>

int f[31];
int fibonacci(int n)
{
	if(n >= 2)
	{
	   f[n] = fibonacci(n-1) + fibonacci(n-2);
	}
	return f[n];
}

int main()
{
	int n,result;
	f[0] = 0;
	f[1] = 1;
	while(scanf("%d",&n) != EOF)
	{
		if(n == 0)
			printf("%d\n",f[0]);
		else if(n == 1)
			printf("%d\n",f[1]);
		else if(n >= 2){
			result = fibonacci(n);
			printf("%d\n",result);
		}else
			break;
	}
	return 0;
} 