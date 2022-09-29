#include <stdio.h> 

int bigger(int a, int b) {
	return a>b ? a : b;
}

int main(void) {
	int N;
	scanf("%d",&N);
	
	int arr[N+1];
	arr[0] = 0;
	for(int i = 1; i <= N; i++) {
		scanf("%d",&arr[i]);
	}
	
	int dp[N+1];
	dp[0] = 0;
	for(int i = 1; i <= N; i++) {
		dp[i] = 1;
		for(int j = 0; j < i; j++) {
			if(arr[i] > arr[j]) {
				dp[i] = bigger(dp[i],dp[j]+1);
			}
		}
		//printf(":%d\n",dp[i]);
	}
	
	int biggest = 1;
	for(int i = 0 ; i <= N; i++) {
		if(dp[i] > biggest) {
			biggest = dp[i];
		}
	}
	printf("%d\n",biggest);
	return 0;
}