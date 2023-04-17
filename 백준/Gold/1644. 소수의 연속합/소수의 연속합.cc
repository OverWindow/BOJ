#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<bool> A;
vector<int> Sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	
	A.resize(4000001,true);
	A[0] = false;
	A[1] = false;
	int tmp = 0;
	Sum.push_back(tmp);
	for(int i = 2; i*i <= 4000000; i++) {
		for(int j = i + i; j <= 4000000; j+=i) {
			A[j] = false;
		}
	} 
	
	for(int i = 2; i < 4000000; i++) {
		if(A[i]) {
			tmp += i;
			Sum.push_back(tmp);	
		}
	}
	/*
	for(int i = 0; i < 20; i++) {
		cout << Sum[i] << " ";
	}*/
	// 2 5 10 17 28
	// sum[i] - sum[j] == N
	int cnt = 0;
	int i = 0;
	int j = 1;
	while(i <= j && j < Sum.size() ) {
		if(Sum[j] - Sum[i] == N) {
			cnt += 1;
			j++;
		} else if(Sum[j] - Sum[i] < N) {
			j++;
		} else if(Sum[j] - Sum[i] > N) {
			i++;
		}
		//cout << i << " " << j << "\n";
	}
	
	cout << cnt << "\n";
	return 0;
}