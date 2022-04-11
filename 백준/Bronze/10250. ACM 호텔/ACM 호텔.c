#include <stdio.h>

int main(void)
{
	int T,H,W,N;
	scanf("%d",&T);
	
	for (int i=0;i<T;i++)
	{
		scanf("%d %d %d",&H,&W,&N);
		if (N%H  == 0)
			printf("%d%02d\n",H,N/H);
		else
			printf("%d%02d\n",N%H,N/H+1);
	}
	return 0;
}