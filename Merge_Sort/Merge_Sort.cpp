#include <stdio.h>

/*void Merge(int r[],int r1[],int s,int m,int t)
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
		Merge(r,r1,s,m,t);
	}	
}

void Binary_Merge_Sort(int r[],int n)
{
	int r1[8];
	Merge_Sort(r,r1,1,n);
}*/

void Merge2(int r[],int p,int q,int t)
{
	int n1 = q-p+1;
	int n2 = t-q;
	int i,j;
	int L[n1],R[n2];
		
	for(i=0; i<n1; i++)
		L[i] = r[p+i-1];
	for(j=0; j<n2; j++)
		R[j] = r[q+j];
		
	L[n1] = 30000; //��ʾ���� 
	R[n2] = 30000;
	i=1;
	j=1;
	
	for(int k = p;k<=t;k++)
	{
		if(L[i]<=R[j])
		{
			if(L[i]!=30000)
			{
				r[k] = L[i];
				i = i+1;	
			}
		}
		else if(L[i]>R[j]) 
		{
			if(R[j]!=30000)
			{
				r[k] = R[j];
				j = j+1; 	
			}
		}
	}
	
	for(i=0;i<8;i++)
	{
	     printf("%d ",r[i]);
	     if(i==7)
	      printf("\n");
	}
}

void Merge_Sort2(int r[],int p,int t)
{
	int q;
	
	if(p < t)
	{
		q=(p+t)/2;
		Merge_Sort2(r,p,q);
		Merge_Sort2(r,q+1,t);
		Merge2(r,p,q,t);
	}	
}

void Binary_Merge_Sort2(int r[],int n)
{
	Merge_Sort2(r,0,n);
}

int main()
{
	int i,num[8];
	
	printf("enter your number:\n");
	for(i=0;i<8;i++)
		scanf("%d",&num[i]);
//	Binary_Merge_Sort(num,8);
	Binary_Merge_Sort2(num,8);
		
	return 0;
}