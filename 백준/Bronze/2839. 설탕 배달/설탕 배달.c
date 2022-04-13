#include <stdio.h>

int main(void)
{
	int kilo, c3 =0, c5 = 0, sum = 0;
	scanf("%d",&kilo);
	
	while (sum<kilo)
	{
		sum += 5;
		c5 += 1;
	}
	
	if (sum == kilo)
	{
		printf("%d",c5);
	}
	else
	{
		do
		{
			while (sum < kilo)
			{
				sum += 3;
				c3 += 1;
			}
			if (sum == kilo)
			{
				break;
			}
			else
			{
				sum -= 3 * c3 + 5;
				c3 = 0;
				c5 -= 1;
			}
		}while(sum != kilo);
		if (c5 < 0)
		{
			printf("-1");
		}
		else
		{
		printf("%d",c3+c5);	
		}
	}
	return 0;
	
}