#include <stdio.h> 
#define M 1000000000
int main(void) {
	int N;
	long long sum = 0;
	scanf("%d",&N);
	
	long long dp[101][10];
	dp[1][0] = 0;
	for(int i = 1 ; i < 10; i++) {
		dp[1][i] = 1; 
		sum += dp[1][i];
	}
	
	if(N == 1) {
		printf("%lld\n",sum);
		return 0;
	}
	for(int i = 2; i <= N; i++) {
		sum = 0;
		for(int j = 0; j < 10; j++) {
			if(j == 0) {
				dp[i][j] = dp[i-1][j+1] % M;
			} else if (j == 9) {
				dp[i][j] = dp[i-1][j-1] % M;
			} else {
				dp[i][j] = (dp[i-1][j-1] % M) + (dp[i-1][j+1] % M);
			}
			sum += dp[i][j];
		}
	}
	
	printf("%lld\n",sum % M);
	return 0;
}