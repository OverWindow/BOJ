#include <stdio.h>

int bigger(int a, int b) {
	return a>b ? a : b;
}

int main(void) {
	int n;
	scanf("%d",&n);
	int arr[100000];
	int finding[100000];
	
	for(int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	
	int biggest = arr[0];
	finding[0] = arr[0];
	
	for(int i = 1; i<n;i++) {
		finding[i]= bigger(finding[i-1]+arr[i],arr[i]);

		biggest = bigger(finding[i],biggest);
	}
	
	printf("%d\n",biggest);
	return 0;
}