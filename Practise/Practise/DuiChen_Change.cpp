/**8位char对称变换   例如
  0101 1101  |  1011 1010
**/
#include "stdafx.h"

unsigned char ch[32] =
{
};

unsigned char change(unsigned char ch)
{
	unsigned char result = 0;
	unsigned char temp  = ch ;
	unsigned 
	int i = 0 ; 
	for(i = 0 ; i < 8 ;i++)
		result = (result<<1) + (unsigned char)((temp>>i) & 0x01);
	return result;
}

/*
int main(void)
{
	int i =0;
	for(i=0; i < 32;i++)
	{
		if(i == 16 )
			printf("\n");
		printf("0x%x,",ch[i]);
	}
	getchar();
}*/
