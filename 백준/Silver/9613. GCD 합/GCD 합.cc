#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int GCD(int a,int b) {
	if(a < b) swap(a,b);
	
	while(1) {
		int tmp = b;
		b = a%b;
		a = tmp;
		
		if(b == 0) break;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	for(int _ = 0; _ < t; _++) {
		int N;
		long long sum = 0;
		cin >> N;
		
		vector<int> A(N,0);
		for(int i = 0; i < N; i++) {
			cin >> A[i];
		}
		
		for(int i = 0; i < N - 1; i++) {
			for(int j = i + 1; j < N; j++) {
				sum += GCD(A[i],A[j]);
			}
		}
		
		cout << sum << "\n";
	}
	return 0;
}