#include "stdafx.h"

#define MAX_VERTEX_NUM 20
#define DEBUG

typedef char VexType ;  //顶点类型；

typedef enum {UNVISITED,VISITED} VisitInfo;

typedef struct ArcNode
{
	VisitInfo mark;   //标记弧是否访问过
	int ivex;    //ivex  jvex表示一段弧的两个顶点
	struct ArcNode *ilink;  //ivex顶点的另一个弧
	int jvex;
	struct ArcNode *jlink;
	int weight;        //弧的权值
}ArcNode;  //弧节点

typedef struct VexNode
{
	VisitInfo mark;   //标记是否访问过
	VexType data;   //顶点的值
	ArcNode *firstArc;
}VexNode;   //图顶点表

typedef struct 
{
	VexNode Vex[MAX_VERTEX_NUM];
	int vexnum;
	int arcnum;
}AMLGraph;   //图 结构


/*图的生成树结构  采用 孩子--兄弟的结构*/
typedef struct CSTree
{ 
	int root;         //指向当前根节点
	struct CSTree *firstchild;  
	struct CSTree *nextbro;
}CSTree;


//定位函数
int Locate(AMLGraph *g , VexType vex)
{
	int i = 0;
	int back;
	while( i < g->vexnum)
	{
		if((g->Vex+i)->data == vex)
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

void CreatAMLGraph(AMLGraph *g)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int weight;
	VexType v1,v2;
	ArcNode *p;

	printf("请输入顶点数，边数 ，格式如1,2:\n");
	scanf("%d,%d",&g->vexnum,&g->arcnum);
	getchar();
	
	//初始化顶点序列
	printf("\n==========现在输入顶点=============\n");
	for(i = 0 ; i < g->vexnum ; i++)
	{
		printf("请输入第%d个顶点值:",i);
		scanf("%c",&(g->Vex+i)->data);
		getchar();
		(g->Vex+i)->firstArc = NULL;
		(g->Vex+i)->mark = UNVISITED;
	}
#ifdef DEBUG
	i =0;
	printf("顶点Vex[]为:");
	while(i<g->vexnum)
	{
		printf("%c--",(g->Vex+i)->data);
		i++;
	}
	printf("\n");
#endif

	//初始化边
	printf("\n==========现在输入弧================\n");
	for(k=0; k < g->arcnum ; k++)
	{
		printf("请输入第%d个弧，格式ab,12,表示a---b之间的弧权值12:\n",k);
		scanf("%c%c,%d",&v1,&v2,&weight);
		getchar();
		i = Locate(g,v1);
		j = Locate(g,v2);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		if(p ==NULL)
		{
			perror("error in malloc:");
			return;
		}
		p->mark = UNVISITED;
		p->ivex = i;
		p->jvex = j;
		p->weight = weight;
		p->ilink = (g->Vex+i)->firstArc;
		p->jlink = (g->Vex+j)->firstArc;

		(g->Vex+i)->firstArc = p;
		(g->Vex+j)->firstArc = p;
	}
}

void PrintAMLGraph(AMLGraph *g)
{
	int i ;
	ArcNode *p;
	printf("\n============Now print all the edage===========\n");
	for(i = 0; i < g->vexnum ;i++)
	{
		printf("============Vex[%d] edage is：\n",i);
		p = (g->Vex+i)->firstArc;
		while(p!=NULL)
		{
			printf("%c---%c\n",(g->Vex+p->ivex)->data,(g->Vex+p->jvex)->data);
			if(p->ivex == i)
				p = p->ilink;
			else if(p->jvex == i)
				p = p->jlink;
			else
			{
				perror("error in Print:\n");
			}
		}
		printf("\n");
	}
}

/**
* 递归深度遍历法  对于单个连通图
  int v ; 为起始顶点
*/
void AMLDFS(AMLGraph *g,int v)
{
	ArcNode *p;

	if((g->Vex+v)->mark == UNVISITED)  //未访问，访问顶点
	{
		printf("顶点 %d 为 %c\n",v , (g->Vex+v)->data);
		(g->Vex+v)->mark = VISITED;
		p = (g->Vex+v)->firstArc;
		while(p != NULL)
		{
			if( p->ivex == v)
			{
				AMLDFS(g,p->jvex);
				p = p->ilink;
			}
			else if(p->jvex == v)
			{
				AMLDFS(g,p->ivex);
				p = p->jlink;
			}
		}
	} 
	
	return;	
}

/*
*  Prim最小生成树算法，此与 书中略有区别，本质一样，都是找出  未访问顶点集  与 已访问顶点集  之间的权值最小的弧
   使用邻接多重表的结构，mst用于存储 最小生成树的n-1个弧  ， v为初始起点
*/
void MiniSpanTree_PRIM(AMLGraph *g , int v, ArcNode **mst)
{
	ArcNode *pArc;   //用于存储当前弧
	ArcNode *lowArc = NULL ;  //
	int weight = 65535;
	int i ,j;
	int vexto ;   //用于表示与当前顶点邻接的另一个顶点

	for(i = 0 ; i < g->vexnum ; i++)   //初始化 U = {v}   因为邻接表中 有mark标志 ，可以用来判断 顶点是否已用
	{
		if(i == v)
			(g->Vex + i)->mark = VISITED;
		else
			(g->Vex+i)->mark = UNVISITED;
	}   

	for( i = 0 ; i < g->vexnum -1 ; i++)  //此层循环 用于生成 最小生成树的 n-1个弧
	{  
		weight = 65535;   //初始化weight
		for(j = 0 ; j < g->vexnum ; j++)  //判断第i个弧 ， 权最小的 弧 存于 lowArc中 ；遍历所有Visited的弧 找出这些弧中 与 未访问弧 权值 最小的弧
		{
			if((g->Vex+j)->mark == VISITED)    
			{
				pArc = (g->Vex+j)->firstArc;
				while(NULL != pArc)      //判断顶点j的所有邻接边
				{
					if(pArc->ivex == j)  
						vexto = pArc->jvex;
					else
						vexto = pArc->ivex;

					if((g->Vex + vexto)->mark == UNVISITED && pArc->weight < weight)
					{
						lowArc = pArc;
						weight = pArc->weight;
					}

					if(pArc->ivex == j)   //
						pArc = pArc->ilink;
					else
						pArc = pArc->jlink;
				}
			}
		}
		mst[i] = lowArc;  //存储最小生成树的边
			 //添加 U 集合
		if((g->Vex + lowArc->ivex)->mark == VISITED)
			(g->Vex + lowArc->jvex)->mark = VISITED;
		else
			(g->Vex + lowArc->ivex)->mark = VISITED;
		
	}

	for(i = 0 ; i < g->vexnum -1; i++)
		{
			printf("弧%d   %c----%c   weight = %d\n",i,(g->Vex+mst[i]->ivex)->data,(g->Vex+mst[i]->jvex)->data,mst[i]->weight);
		}

}


void DFSTree(AMLGraph *g  , CSTree *T)
{
	int w ;
	int first = TRUE;
	ArcNode *nextArc;
	CSTree *p,*q;

	(g->Vex+T->root)->mark = VISITED;   //標記當前節點已被訪問
	printf("\n当前所在节点:%c\n",(g->Vex +T->root)->data);
	nextArc = (g->Vex+ T->root)->firstArc;

	while(NULL != nextArc)
	{
		if(nextArc->ivex == T->root)
		{
			w = nextArc->jvex;
			nextArc = nextArc->ilink;
		}
		else
		{
			w = nextArc->ivex;
			nextArc = nextArc->jlink;
		}
		if((g->Vex+ w)->mark == UNVISITED)
		{
			p = (CSTree*)malloc(sizeof(CSTree));
			p->root = w;
			p->firstchild =NULL;
			p->nextbro =NULL;
			if(first)
			{
				T->firstchild = p;
				first = FALSE;
			}
			else
			{
				q->nextbro = p;
			}
			q = p;
			DFSTree(g,q);
			}
		
	}
}

/*深度优先遍历的生成森林*/
void DFSForest(AMLGraph *g,CSTree *T)
{
	int v;
	int k = 1;
	int first = TRUE;
	int outFlag = 0;
	int outFlagch =0;
	CSTree *p;
	CSTree *q = (CSTree *)malloc(sizeof(CSTree));


	{
		T ->root = 0 ;
		T->firstchild = NULL;
		T->nextbro = NULL;
	}
	printf("\n==========Now DFSForest==============\n");
	for(v = 0 ;v < g->vexnum; v++)
		(g->Vex+v)->mark = UNVISITED;
	for(v = 0 ; v < g->vexnum ; v++)
	{
		if((g->Vex+v)->mark == UNVISITED)   //未访问
		{
			printf("\nfind %dth Tree\n",k++);
			p = (CSTree *)malloc(sizeof(CSTree));
			if( p==NULL)
			{
				perror("error in malloc of DFSForest:");
				return;
			}
			p->root = v;
			p->firstchild = NULL;
			p->nextbro = NULL;
			if(first)  
			{
				first = FALSE;
				T->root = v;
			}
			else 
			{
				q->nextbro = p; 
				if(outFlag++ == 0)   T->nextbro = q->nextbro;   //生成第一个根节点的时候，输出兄弟节点
			}
			q = p;    //q保存当前数的根;
			DFSTree(g,p);
			if(outFlagch++ == 0);
			{
				T->firstchild = q;    //生成第一个根节点的时候，输出孩子节点
			}
		}
	}
}

int main(void)
{
	int i ;
	AMLGraph g;
	CSTree *T = (CSTree *)malloc(sizeof(CSTree));
	ArcNode *mst[MAX_VERTEX_NUM]; 
	for(i = 0 ; i < MAX_VERTEX_NUM;i++)  //初始化
		mst[i]= NULL;

	CreatAMLGraph(&g);
	PrintAMLGraph(&g);
	//遍历，能够遍历访问 非连通图
	for( i = 0 ; i< g.vexnum ; i++)
	{
		if((g.Vex+i)->mark ==UNVISITED)
		{
			printf("================\n");
			AMLDFS(&g,i);
		}
	}
	DFSForest(&g,T);
	MiniSpanTree_PRIM(& g, 0, mst);

	i = 0;
	getchar();
	return 0;
}
