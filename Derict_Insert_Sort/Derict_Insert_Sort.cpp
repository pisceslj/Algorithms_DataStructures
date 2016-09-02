#include <stdio.h>

void Derict_Insert_Sort(int r[],int n)
{
	int i,j;
	for(i=2;i<=n;++i)
	{
		if(r[i]<r[i-1])
		{
			r[0]=r[i];
			for(j=i-1;r[0]<r[j];j--)
				r[j+1]=r[j];
			
			r[j+1]=r[0];
		}
	}
	for(i=1;i<n+1;i++)
	{
		printf("%d ",r[i]);
	}
} 

int main()
{
	int i,num[8];
	printf("enter your number:\n");
	for(i=0;i<8;i++)
	{
		scanf("%d",&num[i]);
	} 
	Derict_Insert_Sort(num,7);
	
	return 0;
}