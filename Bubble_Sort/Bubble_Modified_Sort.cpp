#include <stdio.h>

void Bubble_Modified_Sort(int r[],int n)
{
	int i,j,LastExchngeIndex;
	
	i = n;
	while(i>1)
	{
		LastExchngeIndex = 1;
		for(j=1;j<i;++j)
		{
			if(r[j]>r[j+1])
			{
				r[0]=r[j+1];
				r[j+1]=r[j];
				r[j]=r[0];
				LastExchngeIndex = j;
			}
		}
		i = LastExchngeIndex;
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
		
	Bubble_Modified_Sort(num,8);
	
	return 0;
}