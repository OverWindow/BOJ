#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 2110 binarySearch(parametric)
int N,C;
vector<int> house;
long long ans;

void plant() {
	long long start = 1;
	long long end = house[N-1] - house[0];
	
	while(start <= end) {
		long long mid = (start + end) /2;
		long long cnt = 0;
		//cout << "start: " << start << " end: " << end << " mid: " << mid << "\n";
		long long before = house[0];
		for(int i = 0; i < N; i++) {
			if(house[i] >= before) {
				cnt += 1;
				before = house[i] + mid;
			} 
		}
		if(cnt >= C) {
			ans = max(ans,mid);
			start = mid + 1;
		}  else if(cnt < C) {
			end = mid - 1;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> C;
	house.resize(N,0);
	for(int i = 0; i < N; i++) {
		cin >> house[i];
	}
	sort(house.begin(),house.end());
	
	plant();
	cout << ans << "\n";
	return 0;	
}