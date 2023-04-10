#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 1654 binarySearch(parametric)
long long greatest;
int K,N;
vector<int> bag;

void cut(int maxi) {
	long long i = 1;
	long long j = maxi;
	
	while(i <= j) {
		long long mid = (i + j)/2;
		long long cnt = 0;
		
		//cout << "mid " << mid << "\n";
		for(int k = 0; k < K; k++) {
			cnt += bag[k]/mid;
		}
		
		if(cnt < N) {
			j = mid - 1;
		} else if(cnt >= N) {
			i = mid + 1;
			greatest = max(greatest,mid);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> K >> N;
	bag.resize(K,0);
	greatest = 0;
	int maxi = 0;
	for(int i = 0; i < K; i++) {
		cin >> bag[i];
		maxi = max(maxi,bag[i]);
	}
	
	cut(maxi);
	cout << greatest << "\n";
	return 0;	
}