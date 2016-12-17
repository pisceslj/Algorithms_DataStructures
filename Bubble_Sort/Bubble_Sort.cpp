#include <stdio.h>

void Bubble_Sort(int r[],int n)
{
	int i,j,swap;
	for(i=1;i<n;++i)
	{
		swap = 0;
		for(j=1;j<=n-i;++j)
		{
			if(r[j]>r[j+1])
			{
				r[0]=r[j+1];
				r[j+1]=r[j];
				r[j]=r[0];
				swap = 1;
			}
		if(swap == 0)break; 
		}	
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",r[i]);	
	}
}

int main()
{
	int i,num[8];
	printf("enetr your number:\n");
	for(i=0;i<8;i++)
	{
		scanf("%d",&num[i]);
	}
	Bubble_Sort(num,8);
	
	return 0;
}