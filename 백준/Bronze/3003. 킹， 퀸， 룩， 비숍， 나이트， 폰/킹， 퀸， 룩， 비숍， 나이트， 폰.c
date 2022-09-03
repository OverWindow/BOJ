#include <stdio.h>

int main(void)
{
	int standard[6] = {1,1,2,2,2,8};
	int numbers[6];
	for(int i = 0; i < 6; i++) {
		scanf("%d",&numbers[i]);
	}
	
	for(int i = 0; i < 6; i++) {
		printf("%d ",standard[i] - numbers[i]);
	}
	
	return 0;
}	