/* ���ֲ����㷨 */ 
#include <stdio.h>

void Binary_Insert_Sort(int r[],int n)
{
	int i,j;
	int low,high,mid;
	
	for(i=2;i<=n;++i)
	{
		r[0]=r[i];
		low=1;
		high=i-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(r[0]>r[mid])
				low=mid+1;
			else
				high=mid-1;
		}
		for(j=i-1;j>=high+1;j--)
			r[j+1]=r[j];
		r[high+1]=r[0];
	}
	for(i=0;i<n;i++)
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
	Binary_Insert_Sort(num,7);
	
	return 0;
}
