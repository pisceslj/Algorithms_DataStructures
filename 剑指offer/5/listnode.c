#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "stack.h"

/***************************************/
/**************链表部分******************/
/***************************************/
struct ListNode   //链表节点结构体
{
	int key;
	struct ListNode *next;
};

int n; //节点总数

/***************创建链表************************/
struct ListNode *CreateList()
{
	struct ListNode *head;//头节点
	struct ListNode *p = NULL;//保存新创建的节点地址
	struct ListNode *q = NULL;//保存原链表最后一个节点的地址

	n = 0;//节点数为0
	p = (struct ListNode *)malloc(sizeof(struct ListNode));//开辟一个新的节点空间
	q = p;//备份

	if(p == NULL)
	{
		perror("\nCann't create it, try it again in a moment!\n");
		return NULL;
	}else
	{
		head = NULL;
		printf("输入%d 节点值:",n+1);
		scanf("%d",&(p->key));//录入数据
	}

	while(p->key != 0)
	{
		n = n + 1;
		if(n == 1)//z只有一个节点的情况
		{
			head = p;
			q->next = NULL;
		}else
		{
			q->next = p;
		}

		q = p;//把p的地址给q保留，然后p产生新的节点

		p = (struct ListNode *)malloc(sizeof(struct ListNode));
		printf("输入%d 节点值:",n+1);
		scanf("%d",&(p->key));//录入数据
	}
	q->next = NULL;

	free(p);		//释放指针p
	p = NULL;		//把p的值置为NULL

	return 	head;
}

/*****************遍历链表******************/
void display(struct ListNode *head)
{	
	struct ListNode *p;

	p = head;

	printf("\n正链表如下：\n");
	while(p != NULL)
	{
		if(p->next != NULL)
			printf("%d->",p->key);
		else
			printf("%d\n",p->key);
		push(p->key);	//把每次遍历的节点入栈
		p = p->next;	//p指向下一个节点
	}
	printf("\n");
	
}

/*****************main函数****************/
int main(int argc,char *argv[])
{
	struct ListNode *pHead;

	/*****动态数组堆栈***********/
	create_stack(10);

	pHead = CreateList();	//创建一个链表
	display(pHead);			//打印一个链表	

	print();
	printf("\n");
	destroy_stack();
	
		
	
	/******静态数组堆栈**********/
	//print();
	//printf("\n");

	

	return 0;
	
}








