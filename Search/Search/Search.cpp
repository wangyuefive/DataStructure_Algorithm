// Search.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#define COUNT  20U   //����
#define MAXNUM 30U   //������
#define MINNUM 1U    //��С����
#define DEBUG


/*�Զ��������*/
typedef struct intArray{
	int a[COUNT];
	int length;
}intArray,*pintArray;


/**
*����һ������ΪCOUNT ,��Сλ��MAXNUM-MINNUM֮����������
*����pintArray������ָ��;
*/
pintArray createArray(void)
{
	pintArray result;
	int i = 0;
	int count = 0;
	result = (pintArray)calloc(1,sizeof(intArray));
	if(NULL == result)
	{
		perror("error in calloc");
		return NULL;
	}
	srand((unsigned int)time(NULL));   //���������
	for(i = 0 ; i < COUNT; i++)
	{
		*(result->a+i) = rand() % (MAXNUM+1 -MINNUM) + MINNUM;
		count++;
	}
	result->length = count;
#ifdef DEBUG
	{
		printf("���ɵ���������:����Ϊ%d\n",count);
		for( i = 0 ; i < result->length ; i++)
			printf("%d ",*(result->a+i));
		printf("\n");
	}
#endif
	return result;
}

void clearArray(pintArray arr)
{
	int i=0 ;
	while(i < arr->length)
	{
		*(arr->a+i)= 0;
		i++;
	}
	arr->length = 0;
}

void printArray(int a[],int N)
{
	int i = 0 ;
	while(i < N)
		printf("%d ",a[i++]);
	printf("\n");
}

int getNum(void)
{
	int num;
	printf("\n��������ҵ�����");
	scanf("%d",&num);
	while(getchar()!='\n');
	return num;
}

int _tmain(int argc, _TCHAR* argv[])
{
	pintArray intarray;
	intArray temparray;    //���ڱ����ʼ����
	timeb t1,t2;
	time_t time ;

	intarray = createArray();  //����ԭʼ����
	temparray = *intarray;  
	
	if(NULL == intarray)
	{
		perror("error in creatArray");
		exit(-1);
	}


	getchar();
	return 0;
}

