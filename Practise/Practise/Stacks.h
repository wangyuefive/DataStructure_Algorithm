
#ifndef _STACKS_H
#define _STACKS_H

#include "stdafx.h"

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

#define SElem_Type char       //ջ��������  

#define SElem_SIZE sizeof(SElem_Type)  //���㲻ͬ�������͵�malloc����

#define STACK_INC_SIZE 10   //�ڴ治��ʱ�������
#define STACK_INIT_SIZE 100

/**
*����ջ�Ķ���
*/
typedef struct  
{
	SElem_Type *base;
	SElem_Type *top;
	int stacksize;
}SqStack, *pSqStack;

//��ʼ
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

//����
int  DestroyStack(pSqStack s)
{
	if (s == NULL)
		return ERROR;
	free(s->base);
	s->top = s->base =NULL;
	s->stacksize = 0;
	return OK;
}

//�ÿ�
void  ClearStack(pSqStack s)
{
	s->top = s->base ;
}

//Ϊ��?

int StackEmpty(pSqStack s)
{
	if (s == NULL)
		return ERROR;
	if (s->top == s->base)
		return TRUE;
	return FALSE;
}

//����
int StackLength(pSqStack s)
{
	return s->top - s->base;
}

//ջ��Ԫ��  (ע�⣬��ջ�����һ��Ԫ��topֵ����1,��ָ����һ���µĿռ�)
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
