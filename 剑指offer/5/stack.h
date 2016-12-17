#ifndef __STACK__
#define __STACK__

#include <stdlib.h>

/****************************************/
/*************堆栈部分********************/
/****************************************/

/******************************静态数组实现版堆栈*******************************/
#define STACK_TYPE int //定义堆栈存储数据类型

/**************创建堆栈*******************/
void create_stack(size_t size);

/**************销毁堆栈******************/
void destroy_stack(void);

/***************压栈********************/
void push(STACK_TYPE value);

/***************出栈*******************/
void pop(void);

/****************返回顶部元素值**********/
STACK_TYPE top(void);

/***************判断堆栈是否为空**********/
int is_empty(void);

/***************判断堆栈是否已满**********/
int is_full(void);

void print(void);

#endif



