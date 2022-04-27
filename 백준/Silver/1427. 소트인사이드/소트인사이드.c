#include <stdio.h>

int main(void){

	int arr[10] = {0},i = 0;
	char num;

	for (int m = 0; m < 10 ;m++)
	{
		scanf("%c",&num);
		if (num == '\n')
		{
			arr[i] = -1;
			break;
		}
		int n = num - '0';
		arr[i] = n;
		i += 1;
	}
	for ( int _ = 0; _ < i; _++)
	{
		for ( int j = 0; j < i-1; j++)
		{
			if (arr[j] < arr[j+1])
			{
				int tmp;
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
	
	for ( int k = 0; k<10; k++)
	{	
		if (arr[k] == -1)
			break;
		else
			printf("%d",arr[k]);
	}
	return 0;
}
