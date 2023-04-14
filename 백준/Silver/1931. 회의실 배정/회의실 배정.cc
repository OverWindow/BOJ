#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	vector<pair<int,int>> A(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i].second >> A[i].first;
	}
	
	sort(A.begin(),A.end());
	
	int count = 0;
	int end = -1;
	for(int i = 0; i < N; i++) {
		if(A[i].second >= end) {
			end = A[i].first;
			count += 1;
		}
	}
	cout << count << "\n";
	return 0;
}