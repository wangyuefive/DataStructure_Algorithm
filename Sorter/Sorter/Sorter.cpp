// Sorter.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#define COUNT 100U    //����
#define MAXNUM 1000U   //������
#define MINNUM 1U    //��С����
#define DEBUG

extern void InsertSorter(int a[], int N);
extern void ShellSorter(int a[] , int N);
extern void BasicSorter(int a[], int N);

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
			printf("%d  ",*(result->a+i));
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

void printResult(int a[],int N)
{
	int i = 0 ;
	printf("�����Ľ��Ϊ:\n");
	while(i < N)
		printf("%d ",a[i++]);
	printf("\n");
}

int main(int argc, _TCHAR* argv[])
{
	pintArray intarray;
	timeb t1,t2;
	time_t time ;

	intarray = createArray();
	
	if(NULL == intarray)
	{
		perror("error in creatArray");
		exit(-1);
	}

	printf("/******���ò�������********/\n");
	ftime(&t1);   //��ȡ��ǰʱ��
	InsertSorter(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printResult(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("����ʱ��Ϊ:%ld����\n",time);

	clearArray(intarray);
	intarray = createArray();
	printf("/******����ϣ������********/\n");
	ftime(&t1);   //��ȡ��ǰʱ��
	ShellSorter(intarray->a, intarray->length);
	ftime(&t2);
#ifdef DEBUG
	printResult(intarray->a, intarray->length);
#endif
	time = (t2.time - t1.time)*1000 + (t2.millitm - t1.millitm);
	printf("����ʱ��Ϊ:%ld����\n",time);


	free(intarray);
	getchar();
	return 0;
}

