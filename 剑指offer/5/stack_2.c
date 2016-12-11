#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include "stack.h"

/***************************************动态数组堆栈************************/
/************避免浪费空间*****************/

static STACK_TYPE *stack;//指向堆栈顶部元素的指针
static int stack_size;
static int top_element = -1;

/**************创建堆栈*******************/
void create_stack(size_t size)
{
	assert(stack_size == 0);
	stack_size = size;

	stack = (STACK_TYPE *)malloc(sizeof(STACK_TYPE)*stack_size);
	if(!stack)
	{
		perror("stack malloc failed\n");
		exit(1);
	}
}

/**************销毁堆栈******************/
void destroy_stack(void)
{
	assert(stack_size > 0);
	stack_size = 0;

	free(stack);
	stack = NULL;
}

/***************压栈********************/
void push(STACK_TYPE value)
{
	assert(!is_full());
	top_element += 1;
	stack[top_element] = value;
}

/***************出栈********************/
void pop(void)
{
	assert(!is_empty());
	top_element -= 1;
}

/***************返回顶部元素值************/
STACK_TYPE top(void)
{
	assert(!is_empty());
	return stack[top_element];
}

/**************判断堆栈是否为空**********/
int is_empty(void)
{
	assert(stack_size > 0);	//防止任何堆栈函数在堆栈被创建之前就被调用，必须在create_stack函数之后才能执行
	return top_element == -1;
}

/**************判断堆栈是否已满**********/
int is_full(void)
{
	assert(stack_size > 0);//防止任何堆栈函数在堆栈被创建之前就被调用
	return top_element == stack_size - 1;
}

/**************打印堆栈******************/
void print(void)
{
	int i;
	i = top_element;
	printf("逆链表如下：\n");
	if(i == -1)
		printf("这是一个空链表\n");
	while(i != -1)
	{
		if(i == 0)
			printf("%d",stack[i--]);
		else
			printf("%d->",stack[i--]);
	}
	printf("\n");
}





