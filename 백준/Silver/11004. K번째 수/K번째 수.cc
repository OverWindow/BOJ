#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(vector<int> &A, int S, int E) {
	int tmp = A[S];
	A[S] = A[E];
	A[E] = tmp;
	return;
}

int partition(vector<int> &A, int S, int E) {
	if(S + 1 == E) {
		if(A[S] > A[E]) swap(A,S,E);
		return E;
	}
	
	int M = (S+E)/2;
	swap(A,S,M);
	int pivot = A[S];
	int i = S + 1;
	int j = E;
	
	while(i <= j) {
		while(pivot < A[j] && j > 0) j--;
		while(pivot > A[i] && i < A.size() - 1) i++;
		if( i <= j ) swap(A,i++,j--);
	}
	
	A[S] = A[j];
	A[j] = pivot;
	return j;
}

void quickSort(vector<int> &A, int S, int E, int K) {
	int pivot = partition(A,S,E);
	if(pivot == K) {
		return;
	} else if(K < pivot) {
		quickSort(A,S,pivot - 1,K);
	} else if(K > pivot) {
		quickSort(A,pivot + 1, E,K);
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	
	vector<int> A(N,0);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	quickSort(A,0,N-1,K-1);
	
	cout << A[K-1];
	return 0;
}