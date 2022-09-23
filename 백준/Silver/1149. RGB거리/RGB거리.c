#include <stdio.h>

int smaller(int a, int b) {
	return a>b ? b : a;
}

int main(void) {

	int N;
	scanf("%d",&N);
	
	int cost[3];
	int house[1001][3];
	house[0][0] = 0;
	house[0][1] = 0;
	house[0][2] = 0;
	for(int i = 1 ; i <= N; i++) {
		scanf("%d %d %d",&cost[0],&cost[1],&cost[2]);
		
		house[i][0] = smaller(house[i-1][1],house[i-1][2]) + cost[0];
		house[i][1] = smaller(house[i-1][2],house[i-1][0]) + cost[1];
		house[i][2] = smaller(house[i-1][0],house[i-1][1]) + cost[2];
	}
	
	printf("%d\n",smaller(house[N][0],smaller(house[N][1],house[N][2])));
	return 0;
}

