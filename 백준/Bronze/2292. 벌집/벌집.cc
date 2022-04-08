#include <stdio.h>

int main()
{
	int num,limit=1,count=1;
	scanf("%d",&num);
	
	while(num > limit)
	{
		limit += 6 * count;
		count += 1;
	}
	printf("%d",count);
	return 0;
}