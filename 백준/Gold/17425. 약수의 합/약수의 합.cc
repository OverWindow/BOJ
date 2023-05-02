#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<long long> A(1000001,0);
vector<long long> prefix;

void init() {
	for(long long i = 1; i <= 1000000; i++) {
		for(long long j = i; j <= 1000000; j+=i) {
			A[j] += i;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	init();
	prefix.push_back(0);
	for(int i = 1; i <= 1000000; i++) {
		prefix.push_back(prefix[i-1]+A[i]);
	}
//	for(int i = 1; i<= 10; i++) {
//		cout << A[i] <<" ";
//	}
	
	int T;
	cin >> T;

	
	for(int i = 0; i < T; i++) {
		int temp;
		cin >> temp;
		cout << prefix[temp] << "\n";
	}
	return 0;
}