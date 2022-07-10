#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n,m;
	int* plus = NULL;
	int* minus = NULL;
	
	int num;
	int* op = NULL;
	
	plus = (int*)malloc(10000000 * sizeof(int));
	minus = (int*)malloc(10000000 * sizeof(int));
	op = (int*)malloc(500001 * sizeof(int));
	
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		scanf("%d",&num);
		if(num >= 0) {
			plus[num] += 1;
		} else {
			minus[-1 * num] += 1;
		}
	}
	
	scanf("%d",&m);
	
	for(int i = 0; i < m; i++) {
		scanf(" %d",&op[i]);
	}
	
	for(int i = 0; i < m; i++) {
		if ( op[i] >= 0) {
			printf("%d ",plus[op[i]]);
		} else {
			printf("%d ",minus[-1 * op[i]]);
		}
	}
	
	printf("\n");
	free(plus);
	free(minus);
	free(op);
	return 0;
}