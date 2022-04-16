#include <stdio.h>

int main(void)
{
	int n, arr[246913]={0,} ,cnt = 0;
	

	for(int i = 2; i <= 246912;i++)
	{
		for(int j = 2; j*i<=246912; j++)
		{
			if (arr[i*j] < 1)
				arr[i*j] = 1;
		} 
	}
	arr[1] = 1;
	while (1)
	{
		scanf("%d",&n);
		cnt = 0;
		if (n==0)
			break;
		for (int k = n+1; k<= 2*n; k++)
		{
			if (arr[k]==0)
				cnt += 1;
		}
		printf("%d\n",cnt);
	}	
	return 0;
}