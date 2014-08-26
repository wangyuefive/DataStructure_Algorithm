#include"stdafx.h"

/**
* 整数转字符串
*/
char* Integer2String(int num)
{
	int flag, i , j;
	char temp[30];   //计算机最大能表示64位，大概2^64大概有23位数字
	char *s ;
	flag = (num < 0)? -1:1;  //是否为负数
	num = num * flag; 

	for(i = 0; num > 0 ; i++ )
	{
		temp[i] = num%10 + '0' ;
		num /=10;
	}
	if(flag == -1)	
		temp[i++] = '-';

	s = (char*)malloc((i+1)*sizeof(char));
	if(s == 0)
	{
		perror("error in malloc");
		return 0;
	}
	j=0;
	while(i>=0)
	{
		*(s+j++) = temp[--i];
	}
	*(s+j) = '\0' ;
	return s;

}

/**
*  字符串转整数
*/
int String2Integer(char *s)
{
	int flag = 1 ; 
	int i =0 ;
	int j = 0 ;
	int sum = 0;

	if( 0 == s){
		perror("input paramgram cannot be null");
		return 0;
	}

	if(*s == '-'){
		flag = -1 ;
		i =1;
	}

	while(*(s+i) != '\0')
		sum =sum*10 + *(s+i++)-'0' ;

	return flag*sum;
}


int _tmain(int argc, _TCHAR* argv[])
{

	printf("\n%s",Integer2String(123456789));
	printf("\n%d",String2Integer("123456789"));
	getchar();
	return 0;
}