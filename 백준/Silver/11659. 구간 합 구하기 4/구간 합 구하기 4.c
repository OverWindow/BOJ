#include <stdio.h>

int main(void) {
	int N,M;
	scanf("%d %d",&N,&M);
	
	int arr[N+1];
	long sum[N+1];
	long count = 0;
	sum[0] = 0;
	for(int i = 1 ; i <= N; i++) {
		scanf("%d",&arr[i]);
		count += arr[i];
		sum[i] = count;
	}
	
	for(int i = 0 ; i < M; i++) {
		int start,end;
		scanf("%d %d",&start,&end);
		
		printf("%ld\n",sum[end] - sum[start-1]);
	}

	return 0;
}