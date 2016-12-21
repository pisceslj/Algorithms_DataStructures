#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
	int i;
	long n,a,k = 0;
	int sum = 1;

	while(scanf("%ld%ld",&n,&a))
	{
		k = 0;		
		for(i = 1;i <= n;++i)
		{
			sum *= i;
		}

		while(sum != 0 && sum % a == 0)
		{
			sum = sum / a;
			k++;
		}
		printf("%ld\n",k);
	}

	return 0;
}
