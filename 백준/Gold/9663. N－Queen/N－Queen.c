#include <stdio.h>

int N;
int visited[15][15] = {0,};
int total = 0;

void check(int cnt, int i, int check) {
		for(int j = 1; j <= N; j++) {
			visited[j][i] += check;
		}
		int a = cnt;
		int b = i;
		while(a <= N && b <= N) {
			visited[a][b] += check;
			a += 1;
			b += 1;
		}
		a = cnt;
		b = i;
		while(a <= N && b >= 1) {
			visited[a][b] += check;
			a += 1;
			b -= 1;
		}
}

void dfs(int cnt) {
	
	if(cnt == N+1 ) {
		total += 1;
		return;
	}
	for(int i = 1; i <= N; i++) {
		if(!visited[cnt][i]) {
			visited[cnt][i] += 1;
			check(cnt,i,1);
			dfs(cnt + 1);
			visited[cnt][i] += -1;
			check(cnt,i,-1);
		}
	}	
}

int main(void) {
	
	scanf("%d",&N);
	dfs(1);
	printf("%d\n",total);	
	return 0;
}