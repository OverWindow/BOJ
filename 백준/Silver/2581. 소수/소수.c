#include <stdio.h>

int main(void)
{
	int m,n,j,sum = 0,first = 0;
	scanf("%d",&m);
	scanf("%d",&n);
	
	for (int i = m; i<=n; i++)
	{
		for (j = 2; j<i; j++)
		{
			if (i%j==0)
				break;
		}
		if (i==j)
		{
			sum += i;
			if (first == 0)
				first = i;
		}
	}
	
	if (sum == 0)
		printf("-1");
	else
		printf("%d\n%d",sum,first);
	return 0;
}