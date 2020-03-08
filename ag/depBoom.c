#include <stdio.h>

/*

我决定先用深度优先搜索法搞炸弹
说明：
	# 是墙 ， G怪兽 ， .为空地
*/
int collect[13][13]={0},boom=0,px,py;
char map[13][13] = {
	{'#','#','#','#','#','#','#','#','#','#','#','#','#'},
	{'#','G','G','.','G','G','G','#','G','G','G','.','#'},
	{'#','#','#','.','#','G','#','G','#','G','#','G','#'},
	{'#','.','.','.','.','.','.','.','#','.','.','G','#'},
	{'#','G','#','.','#','#','#','.','#','G','#','G','#'},
	{'#','G','G','.','G','G','G','.','#','.','G','G','#'},
	{'#','G','#','.','#','G','#','.','#','.','#','.','#'},
	{'#','#','G','.','.','.','G','.','.','.','.','.','#'},
	{'#','G','#','.','#','G','#','#','#','.','#','G','#'},
	{'#','.','.','.','G','#','G','G','G','.','G','G','#'},
	{'#','G','#','.','#','G','#','G','#','.','#','G','#'},
	{'#','G','G','.','G','G','G','#','G','.','G','G','#'},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#'}};

/* 返回这个点能搞死多少只怪*/
int getNum(int x,int y)
{
		if(map[x][y] == '#' || map[x][y] == 'G'){
			return 0;
		}
		int total=0;
		int tx=x,ty=y;
		while(tx > 0){
			tx--;
			if(map[tx][y] == 'G'){
				total++;
			}
			if(map[tx][y] == '#'){
				break;
			}
		}
		tx=x,ty=y;
		while(tx < 12){
			tx++;
			if(map[tx][y] == 'G'){
				total++;
			}
			if(map[tx][y] == '#'){
				break;
			}
		}
		tx=x,ty=y;
		while(ty > 0){
			ty--;
			if(map[x][ty] == 'G'){
				total++;
			}
			if(map[x][ty] == '#'){
				break;
			}
		}
		tx=x,ty=y;
		while(ty < 12){
			ty++;
			if(map[x][ty] == 'G'){
				total++;
			}
			if(map[x][ty] == '#'){
				break;
			}
		}

		return total;
}

/* 递归遍历每个空点 */
void dfs(int x, int y)
{


	int i,tx,ty;
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

		if(tx < 0 || tx > 12 || ty < 0 || ty > 13){
			continue;
		}

		if(map[tx][ty] == '#' || map[tx][ty] == 'G'){
			continue;
		}

		if(collect[tx][ty] == 0){

			int total = getNum(tx, ty);

			if(total > boom){
				boom = total;
				px = tx;
				py = ty;
			}

			collect[tx][ty] = 1;

			dfs(tx,ty);

		}
	}

	return;
}


int main(int argc, char const *argv[])
{
	

	dfs(3,3);


	printf("boom is %d,point is (%d,%d)\n", boom,px,py);



	return 0;
}