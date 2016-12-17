#include <stdio.h>

void Shell_Insert_Sort(int r[],int n,int d[],int t)
{
 	int i,j,p,k;
 	
    for(k=0;k<t;++k)
    {
 		p=d[k];
		for(i=p;i<=n;++i)
		{
			if(r[i]<r[i-p])
			{
				r[0]=r[i];
				for(j=i-p;j>0&&r[0]<r[j];j=j-p)
					r[j+p]=r[j];
				r[j+p]=r[0];
			}	
		} 		
 	}
	for(i=0;i<8;i++)
	{
		printf("%d ",r[i]);
	}   
}

int main()
{
	int i,num[8],d[3];
	
	printf("enter your number:\n");
	for(i=0;i<8;i++)
	{
		scanf("%d",&num[i]);
	}
	printf("enter your buchang:\n");
	for(i=0;i<3;i++)
	{
		scanf("%d",&d[i]); 
	}
	Shell_Insert_Sort(num,7,d,3);
	
	return 0;
}