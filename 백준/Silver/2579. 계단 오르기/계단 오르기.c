#include <stdio.h>

int bigger(int a, int b) {
	return a>b ? a : b;
}

int main(void) {
	int N;
    scanf("%d", &N);
 	int dp[301];
 	int stair[301];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &stair[i]);
    }

    dp[0] = 0;
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];
 
    for (int i = 3; i <= N; i++) {
        dp[i] = stair[i] + (bigger(dp[i - 2], stair[i - 1] + dp[i - 3]));
    }

    printf("%d\n", dp[N]);
    return 0;

}