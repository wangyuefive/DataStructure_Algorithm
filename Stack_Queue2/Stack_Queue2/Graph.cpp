#include "stdafx.h"

#define IFINITY 65535
#define MAX_VEX_NUM 100
#define DEBUG

typedef char VexType;
typedef int EdgeType;

typedef struct
{
	VexType Vex[MAX_VEX_NUM];
	EdgeType Edge[MAX_VEX_NUM][MAX_VEX_NUM];
	int Vexnum;
	int Edgenum;
}MGraph;

int Locate(MGraph *g,VexType v)
{
	int i ;
	for(i=0 ; i < g->Vexnum; i++)
	{
		if(v == g->Vex[i])
			break;
	}
	if(i > g->Vexnum)
		return -1;
	return i ;
}

void CreateGraph(MGraph *g)
{
	int i ,j,k,w;
	char v1,v2;
	char temp;
	printf("���붥����Ŀ��Vexnum = ");
	scanf("%d",&(g->Vexnum));
	printf("\n����ߵ���Ŀ��Edgenum = ");
	scanf("%d",&(g->Edgenum));

#ifdef DEBUG
	printf("Vexnum =%d ,edgenum = %d\n",g->Vexnum,g->Edgenum);
#endif
	i = 0;
	printf("�����붥��VexԪ��%d���ַ���",g->Vexnum);
	while(i < g->Vexnum)
	{
		temp = getchar();
		if(temp != '\n')
			g->Vex[i++] = temp;	
	}

	while(getchar() != '\n');   //���ĵ������getchar(),��ֹ��������;

#ifdef DEBUG
	i = 0;
	while(i < g->Vexnum)
	{
		printf("Vex[%d] = %c\n",i,g->Vex[i++]);
	}
#endif
	
	//��ʼ��
	for(i = 0 ; i < g->Vexnum ; i++)
		for( j = 0 ; j < g->Vexnum ; j ++)
			g->Edge[i][j] = 0;
	
	for(k = 0 ; k < g->Edgenum ; k++)
	{
		printf("�������%d�ߵ������Ķ���vx,vy���Լ�<vx,vy>��Ȩֵw����ʽx,y,w:\n",k);
		v1 = getchar();
		v2 = getchar();
		scanf("%d",&w);
		while(getchar() != '\n');
#ifdef DEBUG
		printf("����Ϊ%c %c %d \n",v1 ,v2 , w);
#endif

		i = Locate(g,v1);
		j = Locate(g,v2);
		g->Edge[i][j] = w;   //��<v1,v2>
		g->Edge[j][i] = w;  //�Գƻ�<v2,v1>
	}

}


void printGraph(MGraph *g)
{
	int i , j ;
	for(i = 0 ; i < g->Vexnum ; i++)
	{
		for( j = 0 ; j < g->Vexnum ; j++)
		{
			printf("%2d",g->Edge[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	MGraph g;
	CreateGraph(&g);
	printGraph(&g);
	getchar();
}