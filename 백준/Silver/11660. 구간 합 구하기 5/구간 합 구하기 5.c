#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[1024][1024];
int prefixSum[1025][1025];

int main(void) {
	int N, M;
	scanf("%d %d",&N, &M);
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			scanf("%d",&arr[i][j]);
		}
	}
	
	for(int i = 0; i < 1025; i++) {
		prefixSum[i][0] = 0;
		prefixSum[0][i] = 0;
	}
	
	for(int i = 1; i < N + 1; i++) {
		for(int j = 1; j < N + 1; j++) {
			prefixSum[i][j] = arr[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
		}
	}
	
	for(int i = 0; i < M; i++) {
		int inX, inY, outX, outY;
		scanf("%d %d %d %d",&inX, &inY, &outX, &outY);
		printf("%d\n",prefixSum[outX][outY] - prefixSum[inX - 1][outY] - prefixSum[outX][inY - 1] + prefixSum[inX - 1][inY - 1]);
	}
	
	return 0;
}