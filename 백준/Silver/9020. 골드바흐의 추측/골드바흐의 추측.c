#include <stdio.h>

int main(void)
{
	int t,n,down,up,arr[10001]={0,};
	
	arr[1] = 1;
	for (int i = 2; i <= 10000; i++)
	{
		for (int j = 2; i*j <= 10000; j++)
			arr[i*j]=1;	
	}
	
	
	scanf("%d",&t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d",&n);	
		down = n/2;
		up = n/2;
		
		while (1)
		{
			if ((arr[down] == 0) && (arr[up]==0))
			{
				printf("%d %d\n",down,up);
				break;
			}
			else
			{
				down -= 1;
				up += 1;
			}
		}
	}
	return 0;
}