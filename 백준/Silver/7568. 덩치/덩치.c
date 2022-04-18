#include <stdio.h>

int main(void){
	int t;
	scanf("%d",&t);
	
	int arr[50][2]= {0};
	for(int i = 1; i<=t; i++)
	{
		int weight, height;
		scanf("%d %d",&weight,&height);
		arr[i][0] = weight;
		arr[i][1] = height;
	}	
	for(int i = 1; i<=t; i++)
	{
		int k = 1;
		for(int j = 1; j <= t; j++)
		{
			if ((arr[i][0] < arr[j][0]) && (arr[i][1] < arr[j][1]))
			{
				k += 1;
			}
		}
		printf("%d ",k);
	}
	
	return 0;
}