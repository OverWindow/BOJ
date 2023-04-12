#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

long long N,M,least,sum,biggest;
vector<long long> arr;

void cut() {
	long long start = biggest;
	long long end = sum;
	
	while(start <= end) {
		long long mid = (start + end)/2;
		// ex) mid = 16
		// 1 2 3 4 5 6 7 8 9
		long long length = 0;
		long long cnt = 0;
		for(int i = 0; i < N; i++) {
			if(length + arr[i] > mid) {
				cnt += 1;
				length = 0;
			} 
			length = length + arr[i];	 
		}
		if(length) cnt += 1;
		
		//cout << "mid: " << mid << "\n";

		if(cnt > M) {
			start = mid + 1;
		} else if(cnt <= M) {
			end = mid - 1;
			least = min(least,mid);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	sum = 0;
	biggest = 0;
	arr.resize(N,0);
	for(int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		biggest = max(biggest,arr[i]);
	}
	least = sum;
	cut();
	
	cout << least << "\n";
	return 0;
}