#include <stdio.h>

int n,m;
int arr[8] = {0};


void dfs(int cnt) {
	
	if(cnt == m) {
		for(int i = 0; i < m; i++) {
			printf("%d ",arr[i]);
		}
		printf("\n");
		return;
	}
	
	for(int i = 1; i<= n; i++) {
		arr[cnt] = i;
		dfs(cnt+1);
	}
}

int main(void) {
	
	scanf("%d %d",&n,&m);
	dfs(0);
	return 0;
}