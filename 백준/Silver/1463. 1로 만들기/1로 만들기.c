#include <stdio.h>

int smaller(int a, int b) {
	return a>b ? b : a;
}

int main(void) {
	
	int n;
	scanf("%d",&n);

	int arr[1000001];
	arr[2] = 1;
	arr[3] = 1;
	for(int i = 4; i <= n; i++) {
		arr[i] = arr[i-1] + 1;
		
		if( i % 2 == 0) {
			arr[i] = smaller(arr[i],arr[i/2]+1);
		}
		
		if (i % 3 == 0) {
			arr[i] = smaller(arr[i],arr[i/3]+1);
		}
		
	}
	
	printf("%d\n",arr[n]);
	
	return 0;
}