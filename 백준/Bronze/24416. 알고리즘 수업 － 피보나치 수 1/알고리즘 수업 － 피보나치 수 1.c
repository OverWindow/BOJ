#include <stdio.h>
#include <stdlib.h>

int n;

int fib(int n) {
	if( n == 1 || n == 2) {
		return 1;
	} else {
		return (fib(n-1) + fib(n-2));
	}
}

int f[41];
int fibonacci(int n) {
	f[1] = 1;
	f[2] = 1; 
	int cnt = 0;
	for(int i = 3; i <= n; i++) {
		cnt += 1;
		f[i] = f[i-1] + f[i-2];
	}
	return cnt;
}

int main(void) {
	
	scanf("%d",&n);
	printf("%d %d\n",fib(n),fibonacci(n));
	return 0;
}