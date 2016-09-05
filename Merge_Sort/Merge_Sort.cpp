#include <stdio.h>

void Merge(int r[],int r1[],int s,int m,int t)
{
	int i,j,k;
	
	i=s;
	j=m+1;
	k=s;
	while(i<=m&&j<=t)
	{
		if(r[i]<r[j])
			r1[k++]=r[i++];
		else
			r1[k++]=r[j++];
	}
	while(i<=m)r1[k++]=r[i++];
	while(j<=t)r1[k++]=r[j++];
	
	for(i=0;i<8;i++)
	{
	     printf("%d ",r1[i]);
	     if(i==7)
	      printf("\n");
	}
	
} 

void Merge_Sort(int r[],int r1[],int s,int t)
{
	int m;
	
	if(s==t)
		r1[s]=r[s];
	else
	{
		m=(s+t)/2;
		Merge_Sort(r,r1,s,m);
		Merge_Sort(r,r1,m+1,t);
		Merge(r1,r,s,m,t);
	}	
}

void Binary_Merge_Sort(int r[],int n)
{
	int r1[8];
	Merge_Sort(r,r1,1,n);
}

int main()
{
	int i,num[8];
	
	printf("enter your number:\n");
	for(i=0;i<8;i++)
		scanf("%d",&num[i]);
	Binary_Merge_Sort(num,8);
		
	return 0;
}