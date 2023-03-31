#include <iostream>
using namespace std;

int main(void) {
	int N;
	scanf("%d",&N);
	
	int star = 1;
	for(int i = 0; i < N; i++) {
		for(int j = N - 1 - i; j > 0; j-- ) {
			printf(" ");
		}
		for(int j = 0; j < star; j++) {
			printf("*");
		}
		star += 2;
		printf("\n");
	}
	
	star -= 4;
	for(int i = 0; i < N-1; i++) {
		for(int j = 0; j < i+1; j++) {
			printf(" ");
		}
		for(int j = 0; j < star; j++) {
			printf("*");
		}
		star -= 2;
		printf("\n");
	}
	return 0;
}