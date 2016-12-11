#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include "stack.h"

/************************************链式堆栈*******************************/
/*由于只有堆栈顶部元素才可以被访问，因此适用单链表可以很好实现链式堆栈，而且无长度限制。把一个元素压入堆栈是通过在链表头部添加一个元素实现。弹出一个元素是通过删除链表头部第一个元素实现。由于没有长度限制，故不需要create_stack函数，需要destroy_stack进行释放内存以避免内存泄漏。*/
#define FALSE 0

/***********定义堆栈节点结构体*********************/
typedef struct STACK_NODE
{
	STACK_TYPE value;
	struct STACK_NODE *next;
}StackNode;

static StackNode *stack;//指向堆栈中第一个节点的指针

/***************创建堆栈函数（用不到）****************/
void create_stack(size_t size)
{

}

/**************销毁堆栈函数***********************/
void destroy_stack(void)
{
	while(!is_empty())
	{
		pop();//因为逐个弹出元素，是采用删除节点完成的，逐个释放节点内存
	}
}

/****************入栈***************************/
void push(STACK_TYPE value)
{
	/**************在堆栈链表头部插入新节点**************/
	StackNode *new_node;
	new_node = (StackNode *)malloc(sizeof(struct STACK_NODE));
	if(!new_node)
	{
		perror("node malloc failed\n");
		exit(1);
	}
	new_node->value = value;
	new_node->next = stack; //新节点插入链表头部
	stack = new_node;//更新链表头部 
}

/****************出栈*********************************/
void pop(void)
{
	/*************在堆栈链表中删除头部节点******************/
	StackNode *first_node;
	
	assert(!is_empty());
	first_node = stack;
	stack = first_node->next;
	free(first_node);
}

/**************弹出顶部元素*************************/
STACK_TYPE top(void)
{
	assert(!is_empty());
	return stack->value;//stack指向堆栈第一个指针
}

/**************判断堆栈是否为空*******************/
int is_empty(void)
{
	return stack == NULL;
}

/**************判断堆栈是否已满*******************/
int is_full(void)
{
	return FALSE;
}

/****************打印堆栈*********************/
void print(void)
{
	StackNode *p_node;
	p_node = stack;
	printf("逆链表如下：\n");
	if(p_node == NULL)
		printf("这是一个空堆栈\n");
	while(p_node != NULL)
	{
		if(p_node->next == NULL)
		{
			printf("%d",p_node->value);
			p_node = p_node->next;
		}else
		{
			printf("%d->",p_node->value);
			p_node = p_node->next;
		}			
	}
	printf("\n");
}


