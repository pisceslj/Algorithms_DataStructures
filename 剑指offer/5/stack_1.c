#include <stdio.h>
#include <assert.h>
#include "stack.h"

/******************************静态数组实现版堆栈*******************************/
#define STACK_TYPE int //定义堆栈存储数据类型
#define STACK_SIZE 100 //定义堆栈存储的大小

static STACK_TYPE stack[STACK_SIZE]; //定义堆栈数组
static int top_element = -1; //标记顶点

/***************压栈********************/
void push(STACK_TYPE value)
{
	assert(!is_full());	//判断堆栈是否已满
	top_element += 1;	//顶点指针上移一步		
	stack[top_element] = value;	//将值存入堆栈指定位置
}

/***************出栈*******************/
void pop(void)
{
	assert(!is_empty());	//判断堆栈是否为空
	top_element -= 1;
}

/****************返回顶部元素值**********/
STACK_TYPE top(void)
{
	assert(!is_empty());	//判断堆栈是否为空
	return stack[top_element];	//返回对应值
}

/***************判断堆栈是否为空**********/
int is_empty(void)
{
	return top_element == -1;
}

/***************判断堆栈是否已满**********/
int is_full(void)
{
	return top_element == STACK_SIZE - 1;
}

/****************打印堆栈元素值***********/
void print(void)
{
	int i = top_element;

	printf("逆链表如下：\n");
	if(i == -1)
		printf("这是一个空堆栈\n");
	while(i != -1)
	{
		if(i == 0)
			printf("%d",stack[i--]);
		else
			printf("%d->",stack[i--]);
	}
	printf("\n");
}




