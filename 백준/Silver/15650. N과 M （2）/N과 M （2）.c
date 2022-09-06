#include <stdio.h>

int n,m;
int arr[9] = {0,};
int visited[9] = {0,};

void dfs(int cnt,int overlapPrevent) {
	
	if(cnt == m + 1) {
		for(int i = 1; i <= m; i++) {
			printf("%d ",arr[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i = overlapPrevent; i <= n; i++) {
		if(!visited[i]) {
			visited[i] = 1;
			arr[cnt] = i;
			dfs(cnt+1,i);
			visited[i] = 0;
		}
	}
}

int main(void) {
	
	scanf("%d %d",&n,&m);
	
	dfs(1,1);
	return 0;	
}