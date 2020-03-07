#include <stdio.h>


int arr[9],book[9],n;

void aoshu(index)
{

	if(index > 9){

		if((arr[1]*100+arr[2]*10+arr[3]) + (arr[4]*100+arr[5]*10+arr[6]) = (arr[7]*100+arr[8]*10+arr[9])){
			n++;
			printf("%d%d%d+%d%d%d=%d%d%d\n", arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],arr[8],arr[9]);

		}
		return;
	}


	for (int i = 1; i <= 9; ++i)
	{
		if(book[i] == 0){
			arr[index] = i;
			book[i] = 1;
			aoshu(index+1);
			book[i] = 0;
		}
	}

}

int main(int argc, char const *argv[])
{

	aoshu(1);

	printf("result count is %d\n", n);
	/* code */
	return 0;
}