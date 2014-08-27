#include"stdafx.h"

/**
* google的一道面试题 ， 计算4 000 000 000以内 f(n) = n 的最大的n
* f(n) 统计数字 1，2,3,4，5,6，7,8,9,10,11,12。。。。中1出现的次数
*/


/**
* 获取 1 出现的次数
*/
int getOneCount(int num)
{
	int count = 0;
	while(num > 0)
	{
		if(num % 10 == 1)
			count++;
		num /= 10;
	}
	return count ;
}

int main(void)
{
	double MAX = 4000000000;   //刚开始定义为了 int 型，结果直接超了
	int i = 0;
	int count = 0 ;

	printf("%d\n",getOneCount(101));
	for(i = 0 ; i < MAX ; i++)
	{
		count = count + getOneCount(i);
		if(i == count)
			printf("---------%d\n",i);
	}
	printf("------------------end------------------");
	getchar();
	return 0;
}
