#include <stdio.h>
#include <stdlib.h>

#define KEY_NUM 10  //关键字长度 
#define RADIX 10    //关键字基数，整数时为0-9
typedef int KeyType;
typedef int OtherField; 
typedef struct Node{
	KeyType key[KEY_NUM];
	OtherField otheritem;
	Node *next;
} Node;

typedef struct Queue{
	Node *e; //entry
	Node *f; //fear
}Queue;

Queue queue[RADIX];

void Create_Queue()
{
	printf("please input data numbers:/n");  
    scanf("%d",&queue->e->otheritem);  
    printf("please input keynumbers:/n");  
    scanf("%d",&queue->f->otheritem);  
    printf("please input %d numbers:/n",L.recnum);  
    
}

void Display(Queue queue)
{
	int i,j;
	for(i=queue->e;i;i=queue->f->next)  
    {   
        for(j= KEY_NUM-1;j>=0;j--)  
            printf("%d",queue[i]->e->key[j]);  
        printf(" ");  
    }  
    printf("/n");  
}

void Distribute_Radix(Node **head,int i)
{
	int j;
	Node *p;
	for(j=0;j<RADIX;++j)   //队列置空 
	{
		queue[j]->e = NULL;
		queue[j]->f = NULL;
	}
	for(p = *head;p!=NULL;p=p->next)
	{
		j=ord(p.key[i]);
		if(queue[j]->f == NULL)
			queue[j]->f = p;
		else
			queue[j]->e->next = p;
		Queue[j]->e = p;
	}
}

void Collect_Radix(Node **head,int i)
{
	int j;
	Node *t;
	for(j=0;!queue[j]->f;++j);
	*head = queue[j]->f;
	t = queue[j]->e;
	
	while(j<RADIX)
	{
		for(++j;j<RADIX-1&&!queue[j]->f;++j);
		if(queue[j]->f)
		{
			t->next = queue[j]->f;
			t = queue[j]->e;
		}
	}
	t->next = NULL;	
}

void Radix_Sort(Node **head)
{
	int i;
	for(i=0;i<KEY_NUM;++i)
	{
		Distribute_Radix(*head,i);
		Collect_Radix(*head,i);
	}
}

int main()
{
	Create_Queue(queue);
	printf("Before Sort:\n");
	Display(queue);
	
	Radix_Sort(queue);
	printf("After Sort:\n");
	Display(queue);
	 
	return 0;
}
