
#ifndef _STACKS_H
#define _STACKS_H

#include "stdafx.h"

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

#define SElem_Type char       //栈数据类型  

#define SElem_SIZE sizeof(SElem_Type)  //方便不同数据类型的malloc分配

#define STACK_INC_SIZE 10   //内存不足时候的增量
#define STACK_INIT_SIZE 100

/**
*数据栈的定义
*/
typedef struct  
{
	SElem_Type *base;
	SElem_Type *top;
	int stacksize;
}SqStack, *pSqStack;

//初始
int InitStack(pSqStack s)
{
	if (s == NULL)
		return ERROR;
	s->base = (SElem_Type *)calloc(STACK_INIT_SIZE, sizeof(SElem_Type));
	if (s->base == NULL)
		return (ERROR);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;	
}

//销毁
int  DestroyStack(pSqStack s)
{
	if (s == NULL)
		return ERROR;
	free(s->base);
	s->top = s->base =NULL;
	s->stacksize = 0;
	return OK;
}

//置空
void  ClearStack(pSqStack s)
{
	s->top = s->base ;
}

//为空?

int StackEmpty(pSqStack s)
{
	if (s == NULL)
		return ERROR;
	if (s->top == s->base)
		return TRUE;
	return FALSE;
}

//长度
int StackLength(pSqStack s)
{
	return s->top - s->base;
}

//栈顶元素  (注意，向栈中添加一个元素top值增加1,并指向了一个新的空间)
SElem_Type StackGetTop(pSqStack s)
{
	if (s->top = s->base)
		return ERROR;
	return  (*(s->top-1));
}

int Push(pSqStack s , SElem_Type data)
{
	if(s->top - s->base == s->stacksize)
		{
			s->base = (SElem_Type *)realloc(s->base , (s->stacksize +STACK_INC_SIZE)*SElem_SIZE);
			if (s->base ==NULL)
				return ERROR;
			s->top = s->base + s->stacksize;
			s->stacksize +=STACK_INC_SIZE;
		}
	*(s->top++) = data;
	return OK;
}

int Pop(pSqStack s , SElem_Type *data)
{
	if(s->top == s->base)
		return ERROR;
	*data = *(--s->top);
	return OK;
}

#endif
