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
	}

	int dpRev[N+2];
	dpRev[N+1] = 0;
	for(int i = N; i > 0; i--) {
		dpRev[i] =1;
		for(int j = N; j > i ; j--) {
			if(arr[i]>arr[j]) {
				dpRev[i] = bigger(dpRev[i],dpRev[j]+1);
			}
		}
	}
	/*
	for(int i = 1; i <= N; i++) {
		printf("%d ",dp[i]);
	}
	printf("\n");
	for(int i = 1; i <= N; i++) {
		printf("%d ",dpRev[i]);
	}*/
	
	int result = 0;
	for(int i = 1; i <= N; i++) {
		if(result < dp[i] + dpRev[i])
			result = dp[i] + dpRev[i];
	}
	
	printf("%d\n",result -1);
	return 0;
}