#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int N,M;
	scanf("%d %d",&N,&M);
	
	vector<int> A(N,0);
	vector<int> B(M,0);
	
	for(int i = 0 ; i < N; i++) {
		scanf("%d",&A[i]);
	}
	
	for(int i = 0; i < M; i++) {
		scanf("%d",&B[i]);
	}
	
	vector<int> result(N+M,0);
	
	int i = 0; 
	int j = 0;
	int k = 0; 
	while(1) {
		if(i == N && j == M) {
			break;
		} else if(i == N) {
			result[k] = B[j++];
			k++;
			continue;
		} else if(j == M) {
			result[k] = A[i++];
			k++;
			continue;
		}
		
		if(A[i] > B[j]) {
			result[k] = B[j++];
		} else if (A[i] <= B[j]) {
			result[k] = A[i++];
		}
		k++;
	}
	
	for(int i = 0; i < N+M; i++) {
		printf("%d ",result[i]);
	}
	printf("\n");
	return 0;
} 