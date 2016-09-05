#include <stdio.h>

int Quick_Patition(int r[],int i,int j)
{
	r[0]=r[i];
	while(i<j)
	{
		while(i<j&&r[j]>=r[0])j--;
		if(i<j)
		{
			r[i]=r[j];
			i++;
		}
		while(i<j&&r[i]<=r[0])i++;
		if(i<j)
		{
			r[j]=r[i];
			j--;
		}
	}
	r[i]=r[0];
	
	return i;	
}

void Quick_Sort(int r[],int s,int t)
{
	int i;
	while(s<t)
	{
		i=Quick_Patition(r,s,t);
		Quick_Sort(r,s,i-1);
		Quick_Sort(r,i+1,t);	
	}
	
	for(i=0;i<8;i++)
		printf("%d ",r[i]);
}

int main()
{
	int i,s,t,num[8];
	
	printf("enter your number:\n");
	for(i=0;i<8;i++)
		scanf("%d",&num[i]);
    Quick_Sort(num,0,7);
    
    return 0;
}