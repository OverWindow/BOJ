#include <stdio.h>

int main(void){
	int n,k;
	scanf("%d %d",&n,&k);
	
	int top = 1, bottom1= 1, bottom2 = 1;
	
	for(int i = 1; i <= n; i++ )
	{
		top *= i;
	}
	
	for(int i = 1; i <= k; i++)
	{
		bottom1 *= i;
	}
	
	for(int i = 1; i <= n-k; i++)
	{
		bottom2 *= i;
	}
	
	printf("%d\n",top/(bottom1*bottom2));
	return 0;
}