#include <stdio.h>

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

//ͷ������ 
ListNode* CreateList(ListNode* head)
{
	int i,n,num[6];
	ListNode* p,q;
	
	printf("�������������");
	scanf("%d",&n); 
	printf("��������");
	for(i=0;i<n;i++)
	{ 
		scanf("%d",&num[i]);
	}
	q = (ListNode*)malloc(sizeof(ListNode));
	q->m_pNext=NULL;
	i=n-1;
	while(i>=0)
	{
		p=(ListNode*)malloc(sizeof(ListNode));
		if(!p)
		{
			perror("malloc faied\n");
			break;
		}
		p->m_nKey=num[i];
		p->m_pNext=q->m_pNext;
		q->m_pNext=p;
	}
	
	p->m_pNext->m_nKey = NULL;
	
	return 	head;
}

int main(int argc,char *argv[])
{
	ListNode* pHead;
	CreateList(pHead);
	
	return 0;
	
}