#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N,M;
	scanf("%d %d",&N,&M);
	
	vector<int> A(N+M,0);
	
	for(int i = 0 ; i < N; i++) {
		scanf("%d",&A[i]);
	}
	
	for(int i = N; i < N+M; i++) {
		scanf("%d",&A[i]);
	}
	
	sort(A.begin(),A.end());
	
	for(int i = 0; i < N+M; i++) {
		printf("%d ",A[i]);
	}
	printf("\n");
	return 0;
} 