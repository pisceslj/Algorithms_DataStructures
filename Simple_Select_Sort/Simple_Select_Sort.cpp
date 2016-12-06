#include <stdio.h>

void Simple_Select_Sort(int r[],int n)
{
	int i,j,k;
	for(i=1;i<n;++i)
	{
		k=i;
		for(j=i+1;j<=n;++j)
		{
			if(r[j]<r[k])
				k=j;
		}
		if(i!=k)
		{
			r[0]=r[k];
			r[k]=r[i];
			r[i]=r[0];
		}	
	}
	for(i=0;i<n;i++)
		printf("%d ",r[i]);
}

int main()
{
	int i,num[8];
	
	printf("enter your number:\n");
	for(i=0;i<8;i++)
		scanf("%d",&num[i]);
		
	Simple_Select_Sort(num,8);
	
	return 0;
} 