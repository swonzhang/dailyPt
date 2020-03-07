#include <stdio.h>


/*

解救小哈，使用深度优先搜索

Depth First Search

*/
int arr[5][4] = {
		{1,1,2,1},
		{1,1,1,1},
		{1,1,2,1},
		{1,2,3,1},
		{1,1,2,2},
	},keep,collect[5][4];

void dfs(x,y,step)
{



	if(arr[x][y] == 3){

		if(keep == 0 || step < keep){
			keep=step; 
		}
		return;
	}

	int i,tx,ty;
	for (i = 0; i < 4; ++i)
	{
		if(i == 0){
			tx =x;
			ty = y+1;
		}

		if(i == 1){
			tx = x+1;
			ty = y;
		}

		if(i == 2){
			tx = x;
			ty = y-1;
		}

		if(i == 3){
			tx = x-1;
			ty = y;
		}

		if(tx<0 || tx>4 || ty<0 || ty>3){
			continue;
		}
		if(arr[tx][ty] == 2){
			continue;
		}
		if(collect[tx][ty] == 0){
			collect[tx][ty] = 1;
			dfs(tx,ty,step+1);
			collect[tx][ty] = 0;
		}
		

	}

}



int main(int argc, char const *argv[])
{	

	dfs(0,0,0);


	printf("result is %d\n", keep);
	
	return 0;
}