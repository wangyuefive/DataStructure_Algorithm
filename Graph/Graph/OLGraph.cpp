#include "stdafx.h"

typedef char VexType ;   /*顶点的类型  , 这里定义为char型*/
#define MAX_VEX_NUM 20
#define DEBUG

typedef struct ArcNode
{
	int tailvex,headvex;   /*表示  tailvex---->headvex的弧*/
	ArcNode *hlink;
	ArcNode *tlink;
	int weight;
}ArcNode;   /*弧节点*/  

typedef struct VexNode
{
	VexType data;  /*顶点组成的表*/
	ArcNode *firstin;
	ArcNode *firstout;
}VexNode;

typedef struct
{
	VexNode Vex[MAX_VEX_NUM];
	int vexnum;
	int arcnum;
}OLGraph;

//定位函数
int Locate(OLGraph *g , VexType vex)
{
	int i = 0;
	int back;
	while( i < g->vexnum)
	{
		if(((g->Vex)+i)->data == vex)
		{
			back = i ;
			break;
		}
		i++;
	}
	if( i > g->vexnum)
		back = -1;
	return back;
}

void CreatOLGraph(OLGraph *g)
{
	int i ,j,k;
	VexType v1;
	VexType v2;
	ArcNode *p;

	puts("请输入顶点数和弧数:比如2,3\n");
	scanf("%d,%d",&(g->vexnum),&(g->arcnum));
	while(getchar()!='\n');
	printf("vexnum = %d ,arcnum =%d\n",g->vexnum,g->arcnum);
	
	/*初始化顶点表*/
	for(i = 0 ; i < g->vexnum ; i++)
	{
		printf("请输入第%d个顶点元素的值(字符型)\n",i);
		scanf("%c",&((g->Vex+i)->data));
		while(getchar()!='\n');
		(g->Vex+i)->firstin = NULL;
		(g->Vex+i)->firstout = NULL;
	}

	/*初始化弧表*/
	for(k = 0; k <g->arcnum ; k++)
	{
		printf("请输入第%d个弧,格式v1v2:\n",k);
		v1 = getchar();
		v2 = getchar();
		while(getchar()!='\n');
		printf("输入v1 = %c ,v2 = %c\n",v1,v2);
		i = Locate(g,v1);
		j = Locate(g,v2);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		if( p == NULL)
		{
			perror("error in malloc");
			return ;
		}
		{
			p->tailvex = i;
			p->headvex = j;
			p->hlink = (g->Vex + j)->firstin;
			p->tlink = (g->Vex + i)->firstout;
		}
		(g->Vex+j)->firstin = (g->Vex + i)->firstout = p;					
	}
}

void PrintOLGraph(OLGraph *g)
{
	int i = 0;
	ArcNode *p;
	printf("\nNow display all the arc\n");
	for(i = 0 ; i < g->vexnum ; i++)
	{
		p = (g->Vex + i)->firstout;
		while(p != NULL)
		{
			printf("the arc is : %c---->%c\n",(g->Vex + p->tailvex)->data,(g->Vex + p->headvex)->data);
			p = p->tlink;
		}
	}
}
/*
int main(void)
{
	OLGraph g;
	CreatOLGraph(&g);
	PrintOLGraph(&g);
	getchar();
	return 0;
}*/
