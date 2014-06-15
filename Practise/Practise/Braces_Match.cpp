#include "stdafx.h"
/*
#include "Stacks.h"

//#define DEBUG

#define MAX_STRING_NUM 10000

int getBraces(char **str , int num)
{
	int i = 0 ;
	int j = 0;
	char temp[MAX_STRING_NUM] = "";
	for (i = 0 ; i < num ; i++)
	{
		printf("请输入第%d个字符串:\n",i);
		if(gets(temp)==NULL)
			{
				perror("ERROR in gets():");
				return 1;
			}
		if(str[i] = (char *)calloc(sizeof(char),strlen(temp)));
		strcpy(str[i],temp);	
	}

	#ifdef DEBUG
	printf("============\n");
	for(i = 0 ; i < num ; i++)
		printf("%d  %s\n",str[i],str[i]);
	#endif

	return 0;
}

void Judge(char **str,int num)
{
	int i,j;
	int len;
	SElem_Type temp;
	SqStack s;
	InitStack(&s);
	for(i = 0 ; i < num ; i++)
		{
			len = strlen(str[i]);
			for( j = 0 ; j < len ; j++)
				{
					if(*(*(str+i)+j) == '(' || *(*(str+i)+j) == '[' )
						{
							Push(&s,*(*(str+i)+j));
						}
					else   //右括号
						{
							temp = StackGetTop(&s);
							if((temp == '(' && *(*(str+i)+j) == ')') || (temp== '[' && *(*(str+i)+j) == ']'))
								Pop(&s, &temp);
							else
								{
									printf("NO\n");
									break;
								}
						}
					if(i == len -1 && StackEmpty(&s))
						{
							printf("YES\n");
							break;
						}
						
				}
				
		}
}
/*
int main(void)
{
	int num;
	int i , j ;
	char *str[MAX_STRING_NUM];
	printf("字符串个数:");
	scanf("%d",&num);
	getchar();  //吃掉结尾的'\n'
	getBraces(str, num);
	puts("输出结果为：\n");
	Judge(str,num);
	getchar();
}*/