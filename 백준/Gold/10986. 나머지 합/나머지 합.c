#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long r[1001];

int main(void) {
	int N, M;
	long long sum = 0;
	scanf("%d %d",&N, &M);
		
	int num;
	for(int i = 0 ; i < N; i++) {
		scanf("%d",&num);
		sum += num;
		r[sum % M]++;
	}

	long long result = r[0];
	for(int i = 0; i <= 1000; i++) {
		result += (r[i] * (r[i] - 1)) / 2;
	}
	
	printf("%lld\n",result);
	return 0;
}