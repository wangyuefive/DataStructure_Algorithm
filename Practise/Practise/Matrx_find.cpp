#include"stdafx.h"

#define ROW 4
#define COLUMN 4

int a[ROW][COLUMN]={1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};

int halfFind_Row(int (*a)[COLUMN], int e)
{
	int low = 0 ;
	int high = ROW - 1 ;
	int center = 0;

	if(a[0][0] > e || a[ROW-1][COLUMN-1] < e)
		return -1;
	while(low < high)
	{
		center = (low + high)/2;
		if(a[center][0] <= e && a[center + 1][0] > e)
			return center ;
		else if(a[center][0] > e){
			high = center ;
		}else{
			low = center + 1 ;
		}
	}
}

int main(void)
{
	int row,column ;
	row = halfFind_Row(a , 7);
	if(row >= 0)
		printf("a[%d][0] = %d",row,a[row][0]);
	else
		printf("%d",row);
	getchar();
}