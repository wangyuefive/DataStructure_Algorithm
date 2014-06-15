#include "stdafx.h"

#define MAX_VERTEX_NUM 20
#define DEBUG

typedef char VexType ;  //�������ͣ�

typedef enum {UNVISITED,VISITED} VisitInfo;

typedef struct ArcNode
{
	VisitInfo mark;   //��ǻ��Ƿ���ʹ�
	int ivex;    //ivex  jvex��ʾһ�λ�����������
	struct ArcNode *ilink;  //ivex�������һ����
	int jvex;
	struct ArcNode *jlink;
	int weight;        //����Ȩֵ
}ArcNode;  //���ڵ�

typedef struct VexNode
{
	VisitInfo mark;   //����Ƿ���ʹ�
	VexType data;   //�����ֵ
	ArcNode *firstArc;
}VexNode;   //ͼ�����

typedef struct 
{
	VexNode Vex[MAX_VERTEX_NUM];
	int vexnum;
	int arcnum;
}AMLGraph;   //ͼ �ṹ


/*ͼ���������ṹ  ���� ����--�ֵܵĽṹ*/
typedef struct CSTree
{ 
	int root;         //ָ��ǰ���ڵ�
	struct CSTree *firstchild;  
	struct CSTree *nextbro;
}CSTree;


//��λ����
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

	printf("�����붥���������� ����ʽ��1,2:\n");
	scanf("%d,%d",&g->vexnum,&g->arcnum);
	getchar();
	
	//��ʼ����������
	printf("\n==========�������붥��=============\n");
	for(i = 0 ; i < g->vexnum ; i++)
	{
		printf("�������%d������ֵ:",i);
		scanf("%c",&(g->Vex+i)->data);
		getchar();
		(g->Vex+i)->firstArc = NULL;
		(g->Vex+i)->mark = UNVISITED;
	}
#ifdef DEBUG
	i =0;
	printf("����Vex[]Ϊ:");
	while(i<g->vexnum)
	{
		printf("%c--",(g->Vex+i)->data);
		i++;
	}
	printf("\n");
#endif

	//��ʼ����
	printf("\n==========�������뻡================\n");
	for(k=0; k < g->arcnum ; k++)
	{
		printf("�������%d��������ʽab,12,��ʾa---b֮��Ļ�Ȩֵ12:\n",k);
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
		printf("============Vex[%d] edage is��\n",i);
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
* �ݹ���ȱ�����  ���ڵ�����ͨͼ
  int v ; Ϊ��ʼ����
*/
void AMLDFS(AMLGraph *g,int v)
{
	ArcNode *p;

	if((g->Vex+v)->mark == UNVISITED)  //δ���ʣ����ʶ���
	{
		printf("���� %d Ϊ %c\n",v , (g->Vex+v)->data);
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
*  Prim��С�������㷨������ �����������𣬱���һ���������ҳ�  δ���ʶ��㼯  �� �ѷ��ʶ��㼯  ֮���Ȩֵ��С�Ļ�
   ʹ���ڽӶ��ر�Ľṹ��mst���ڴ洢 ��С��������n-1����  �� vΪ��ʼ���
*/
void MiniSpanTree_PRIM(AMLGraph *g , int v, ArcNode **mst)
{
	ArcNode *pArc;   //���ڴ洢��ǰ��
	ArcNode *lowArc = NULL ;  //
	int weight = 65535;
	int i ,j;
	int vexto ;   //���ڱ�ʾ�뵱ǰ�����ڽӵ���һ������

	for(i = 0 ; i < g->vexnum ; i++)   //��ʼ�� U = {v}   ��Ϊ�ڽӱ��� ��mark��־ �����������ж� �����Ƿ�����
	{
		if(i == v)
			(g->Vex + i)->mark = VISITED;
		else
			(g->Vex+i)->mark = UNVISITED;
	}   

	for( i = 0 ; i < g->vexnum -1 ; i++)  //�˲�ѭ�� �������� ��С�������� n-1����
	{  
		weight = 65535;   //��ʼ��weight
		for(j = 0 ; j < g->vexnum ; j++)  //�жϵ�i���� �� Ȩ��С�� �� ���� lowArc�� ����������Visited�Ļ� �ҳ���Щ���� �� δ���ʻ� Ȩֵ ��С�Ļ�
		{
			if((g->Vex+j)->mark == VISITED)    
			{
				pArc = (g->Vex+j)->firstArc;
				while(NULL != pArc)      //�ж϶���j�������ڽӱ�
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
		mst[i] = lowArc;  //�洢��С�������ı�
			 //��� U ����
		if((g->Vex + lowArc->ivex)->mark == VISITED)
			(g->Vex + lowArc->jvex)->mark = VISITED;
		else
			(g->Vex + lowArc->ivex)->mark = VISITED;
		
	}

	for(i = 0 ; i < g->vexnum -1; i++)
		{
			printf("��%d   %c----%c   weight = %d\n",i,(g->Vex+mst[i]->ivex)->data,(g->Vex+mst[i]->jvex)->data,mst[i]->weight);
		}

}


void DFSTree(AMLGraph *g  , CSTree *T)
{
	int w ;
	int first = TRUE;
	ArcNode *nextArc;
	CSTree *p,*q;

	(g->Vex+T->root)->mark = VISITED;   //��ӛ��ǰ���c�ѱ��L��
	printf("\n��ǰ���ڽڵ�:%c\n",(g->Vex +T->root)->data);
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

/*������ȱ���������ɭ��*/
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
		if((g->Vex+v)->mark == UNVISITED)   //δ����
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
				if(outFlag++ == 0)   T->nextbro = q->nextbro;   //���ɵ�һ�����ڵ��ʱ������ֵܽڵ�
			}
			q = p;    //q���浱ǰ���ĸ�;
			DFSTree(g,p);
			if(outFlagch++ == 0);
			{
				T->firstchild = q;    //���ɵ�һ�����ڵ��ʱ��������ӽڵ�
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
	for(i = 0 ; i < MAX_VERTEX_NUM;i++)  //��ʼ��
		mst[i]= NULL;

	CreatAMLGraph(&g);
	PrintAMLGraph(&g);
	//�������ܹ��������� ����ͨͼ
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
