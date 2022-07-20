#include <stdio.h>

int main(void) 
{
	int n,result = 0;
	
	scanf("%d",&n);
	
	for(int i = 1; i<=n; i++) {
		int tmp = i;
		while (tmp % 5 == 0) {
			tmp /= 5;
			result += 1;
		}
	}
	
	printf("%d\n",result);
	return 0;
}