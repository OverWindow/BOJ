#include <stdio.h>

int N;
int array[1000001];

void cases(void) {
	array[0] = 1;
	array[1] = 1;
	for(int i = 2; i <= 1000000; i++) {
		array[i] = (array[i-1] + array[i-2]) % 15746;
	}
}


int main(void) {

	scanf("%d",&N);
	cases();
	printf("%d\n",array[N]);
	return 0;
}