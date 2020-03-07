#include <stdio.h>

int book[10],arr[10],n;

void dfs(int step)
{	
	int i;
	if(step >= n+1){

		for (i = 1; i < step; ++i)
		{
			printf("%d", arr[i]);
		}
		printf("\n");
		return;
	}


	for (i = 1; i <= n; ++i)
	{
		if(book[i] == 0){

			arr[step] = i;
			book[i] = 1;
			dfs(step+1);

			book[i] = 0;
		}

	}


}


int main(int argc, char const *argv[])
{
	
	n=9;
	dfs(1);

	return 0;
}