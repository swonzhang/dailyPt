#include <stdio.h>

/*

解救小哈，使用广度优先搜索

Breadth First Search

*/

struct breadth
{
	int x;
	int y;
	int step;
	
};


int main(int argc, char const *argv[])
{
	
	int arr[5][4] = {
		{1,1,2,1},
		{1,1,1,1},
		{1,1,2,1},
		{1,2,3,1},
		{1,1,2,2},
	},head=1,tail=1,i,collect[5][4]={0};

	struct breadth tree[1500];

	tree[tail].x=0;
	tree[tail].y=0;
	tree[tail].step=0;

	collect[0][0] = 1;


	int tx,ty,x,y,k=0;

	while(head <= tail){

		x = tree[head].x;
		y = tree[head].y;

		printf("\nhead is %d,x is %d,y is %d\n", head,x,y);
		for (i = 0; i < 4; ++i)
		{
			if(i == 0){
				tx =x;ty = y+1;
			}
			if(i == 1){
				tx = x+1;ty = y;
			}
			if(i == 2){
				tx = x;ty = y-1;
			}
			if(i == 3){
				tx = x-1;ty = y;
			}


			if(tx<0 || tx>4 || ty<0 || ty>3){
				continue;
			}
			if(arr[tx][ty] == 2){
				continue;
			}

			if(collect[tx][ty] == 0){
				tail++;
				tree[tail].x = tx;
				tree[tail].y = ty;
				tree[tail].step = tree[head].step+1;

				collect[tx][ty] = 1;

				if(arr[tx][ty] == 3){
					k=1;
					break;
				}
			}
		}
		int a;
		for (a = 1; a < 4; ++a)
		{
			printf("x-%d,y-%d,step-%d\n", tree[a].x,tree[a].y,tree[a].step);
		}
		
		if(k == 1){
			break;
		}

		head++;

	}

	printf("resulr is %d\n", tree[tail].step);


	return 0;
}