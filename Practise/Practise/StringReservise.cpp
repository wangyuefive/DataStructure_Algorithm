#include"stdafx.h"

/**
* 字符串倒转  如 I come from China. ---> China. from come I
*/

/**
* 将下标为low---high的字符串倒转 ，包括 low 和high
*/
void Traverse(char *s, int low, int high)
{
	int i =0;
	int len = high - low +1;
	char *temp ;

	if(null == s)
	{
		perror("input param s cannot be null");
		return ;
	}

	if(null == (temp = (char*)malloc(len*sizeof(char))))
	{
		perror("error in malloc");
		return;
	}

	while(i < len)
	{
		*(temp+i) = *(s + high - i);
		i++ ;
	}
	i = 0;
	while(i < len)
	{
		*(s + low + i) = *(temp + i) ;
		i++ ;
	}
	free(temp);
}

void StrTraverse(char *s)
{
	int len ;
	int low = 0 ;
	int high ;
	int i = 0;

	if(null == s) return ;
	len = strlen(s);
	high = len -1;

	Traverse(s, low,  high) ;  //整句倒转

	for(i = 0 ; i < len ; i++)
	{
		if(*(s + i) == ' ' || i == len -1)
		{
			high = i - 1;
			Traverse(s, low, high) ;   //部分单词倒转
			low = i + 1;
		}
	}

}


int main(void)
{
	char s[40] = "I come from China.   you";
	StrTraverse(s);
	printf("%s",s);
	getchar();
	return 0;
}