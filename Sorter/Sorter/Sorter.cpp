// Sorter.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#define COUNT 10000U    //����
#define MAXNUM 1000000U   //������
#define MINNUM 1U    //��С����
//#define DEBUG

extern void InsertSorter(int a[], int N);
extern void ShellSorter(int a[] , int N);
extern void BasicSorter(int a[], int N);
extern void ShellSorter_Hibbard(int a[] , const int N);
extern void HeapSorter(int a[] , int N);

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

int main(int argc, _TCHAR* argv[])
{
	pintArray intarray;
	intArray temparray;    //���ڱ����ʼ����
	timeb t1,t2;
	time_t time ;

	intarray = createArray();
	temparray = *intarray;  
	
	if(NULL == intarray)
	{
		perror("error in creatArray");
		exit(-1);
	}
	
	printf("\n\n\n");
	printf("/******���û���ð������********/\n");
	ftime(&t1);   //��ȡ��ǰʱ��
	BasicSorter(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printf("�����Ľ��Ϊ:\n");
	printArray(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("����ʱ��Ϊ:%ld����\n",time);

	printf("\n\n\n");
	*intarray =temparray;
	printf("/******���ò�������********/\n");
#ifdef DEBUG
	printf("��ʼ����Ϊ:\n");
	printArray(intarray->a, intarray->length);
#endif
	ftime(&t1);   //��ȡ��ǰʱ��
	InsertSorter(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printf("�����Ľ��Ϊ:\n");
	printArray(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("����ʱ��Ϊ:%ld����\n",time);

	printf("\n\n\n");
	*intarray =temparray;
	printf("/******����ϣ��_������������********/\n");
#ifdef DEBUG
	printf("��ʼ����Ϊ:\n");
	printArray(intarray->a, intarray->length);
#endif
	ftime(&t1);   //��ȡ��ǰʱ��
	ShellSorter(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printf("�����Ľ��Ϊ:\n");
	printArray(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("����ʱ��Ϊ:%ld����\n",time);


	printf("\n\n\n");
	*intarray =temparray;
	printf("/******����ϣ��_Hibbard��������********/\n");
#ifdef DEBUG
	printf("��ʼ����Ϊ:\n");
	printArray(intarray->a, intarray->length);
#endif
	ftime(&t1);   //��ȡ��ǰʱ��
	ShellSorter_Hibbard(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printf("�����Ľ��Ϊ:\n");
	printArray(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("����ʱ��Ϊ:%ld����\n",time);


	printf("\n\n\n");
	*intarray =temparray;
	printf("/******���ö�����********/\n");
#ifdef DEBUG
	printf("��ʼ����Ϊ:\n");
	printArray(intarray->a, intarray->length);
#endif
	ftime(&t1);   //��ȡ��ǰʱ��
	HeapSorter(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printf("�����Ľ��Ϊ:\n");
	printArray(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("����ʱ��Ϊ:%ld����\n",time);


	free(intarray);
	getchar();
	return 0;
}

