/* ͨ��Huffman��������������� */
/* ��main�������Ե����ϲ���ж� */
/* �ڸ��ڵ���࣬����Ϊ0���Ҳ࣬����Ϊ1 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2-1

typedef struct
{
	int bit[MAXBIT];
	int start;
} HCodeType;     //������ṹ
typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
	int value;
} HNodeType;    //���ṹ��

/* ����Huffman�� */
void HuffmanTree(HNodeType HuffNode[MAXNODE],int n)
{
	/* i,j:ѭ������ */
	/* m1��m2:����huffman����ͬ������������СȨֵ����Ȩֵ */
	/* x1��x2:����huffman����ͬ������������СȨֵ����������е���� */
	int i,j,m1,m2,x1,x2; 
    
    for(i=0;i<2*n-1;i++)
    {
    	HuffNode[i].weight = 0;
    	HuffNode[i].parent = -1;
    	HuffNode[i].lchild = -1;
    	HuffNode[i].rchild = -1;
    }
    
    /* ����n��Ҷ�ӽ���Ȩֵ */
    for(i=0;i<n;i++)
    {
    	printf("Input weight of leaf node %d:\n",i);
		scanf("%d",&HuffNode[i].weight);	
    }
    
    /* ѭ������Huffman�� */
    for(i=0;i<n-1;i++)
    {
    	m1=m2=MAXVALUE;
    	x1=x2=0;
    	/* �ҳ������Ȩֵ��С���޸��ڵ�������ڵ㣬���ϲ�Ϊһ�Ŷ����� */
        for(j=0;j<n+i;j++)
		{
			if(HuffNode[j].weight < m1 && HuffNode[j].parent==-1)
			{
				m2=m1;
				x2=x1;
				m1=HuffNode[j].weight;
				x1=j;
			}
			else if(HuffNode[j].weight < m2 && HuffNode[j].parent==-1)
			{
				m2=HuffNode[j].weight;
				x2=j;
			}
		} 
		
		HuffNode[x1].parent = n+i;
		HuffNode[x2].parent = n+i;
		HuffNode[n+i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
		HuffNode[n+i].lchild = x1;
		HuffNode[n+i].rchild = x2;
		
        printf ("x1.weight and x2.weight in round %d: %d, %d\n", i+1, HuffNode[x1].weight, HuffNode[x2].weight);  /* ���ڲ��� */
        printf ("\n");
	}
}

/* ���� */
void decodeing(char string[],HNodeType Buf[],int Num)
{
	int i,tmp=0,code[1024];
	int m=2*Num-1;
	char *nump;
	char num[1024];
	for(i=0;i<strlen(string);i++)
	{
		if(string[i]=='0')
			num[i]=0;
		else 
			num[i]=1;
	}	
	i=0;
	nump=&num[0];
	
	while(nump<(&num[strlen(string)]))
	{
		tmp=m-1;
		while((Buf[tmp].lchild!=-1)&&(Buf[tmp].rchild!=-1))
		{
			if(*nump==0)
			{
				tmp=Buf[tmp].lchild;
			}
			else
				tmp=Buf[tmp].rchild;
			nump++;
		}
		printf("%d",Buf[tmp].value);
	}
} 

int main(void)
{
	HNodeType HuffNode[MAXNODE];
	HCodeType HuffCode[MAXLEAF],cd;
	
	int i,j,c,p,n;
	char pp[100];
	printf("please input n:\n");
	scanf("%d",&n);
	HuffmanTree(HuffNode,n);
	
	for(i=0;i<n;i++)
	{
		cd.start = n-1;
		c = i;
		p = HuffNode[c].parent;
		while(p!=-1)
		{
			if(HuffNode[p].lchild == c)
				cd.bit[cd.start] = 0;
			else
				cd.bit[cd.start] = 1;
			cd.start--;
			c=p;
			p=HuffNode[c].parent;
		}
		
		for(j=cd.start+1;j<n;j++)
		{
			HuffCode[i].bit[j] = cd.bit[j];
			HuffCode[i].start = cd.start;
		}
		
		for(i=0;i<n;i++)
		{
			printf("%d 's Huffman code is:",i);
			for(j=HuffCode[i].start+1;j<n;j++)
			{
				printf("%d",HuffCode[i].bit[j]);
			}
			printf("start:%d",HuffCode[i].start);
			printf("\n");
		}
		printf("Please enter code:\n");
		scanf("%s",&pp);
		printf("the code is as follows:\n");
		decodeing(pp,HuffNode,n);
		getchar();
		
		return 0;
	}
}