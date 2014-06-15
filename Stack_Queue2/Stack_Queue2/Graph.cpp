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
	printf("输入顶点数目：Vexnum = ");
	scanf("%d",&(g->Vexnum));
	printf("\n输入边的数目：Edgenum = ");
	scanf("%d",&(g->Edgenum));

#ifdef DEBUG
	printf("Vexnum =%d ,edgenum = %d\n",g->Vexnum,g->Edgenum);
#endif
	i = 0;
	printf("请输入顶点Vex元素%d个字符：",g->Vexnum);
	while(i < g->Vexnum)
	{
		temp = getchar();
		if(temp != '\n')
			g->Vex[i++] = temp;	
	}

	while(getchar() != '\n');   //消耗掉多余的getchar(),防止过多输入;

#ifdef DEBUG
	i = 0;
	while(i < g->Vexnum)
	{
		printf("Vex[%d] = %c\n",i,g->Vex[i++]);
	}
#endif
	
	//初始化
	for(i = 0 ; i < g->Vexnum ; i++)
		for( j = 0 ; j < g->Vexnum ; j ++)
			g->Edge[i][j] = 0;
	
	for(k = 0 ; k < g->Edgenum ; k++)
	{
		printf("请输入第%d边的依附的顶点vx,vy，以及<vx,vy>的权值w，格式x,y,w:\n",k);
		v1 = getchar();
		v2 = getchar();
		scanf("%d",&w);
		while(getchar() != '\n');
#ifdef DEBUG
		printf("输入为%c %c %d \n",v1 ,v2 , w);
#endif

		i = Locate(g,v1);
		j = Locate(g,v2);
		g->Edge[i][j] = w;   //弧<v1,v2>
		g->Edge[j][i] = w;  //对称弧<v2,v1>
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