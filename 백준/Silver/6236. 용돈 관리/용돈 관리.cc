#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> A;
int sum,high,ans;

void Search(int N,int M) {
	int start = high;
	int end = sum;
	
	// 100 400 300 100 500 101 400
	while(start <= end) {
		int mid = (start + end)/2;
		long long cnt = 1;
		//cout << "mid: " << mid << "\n";
		
		int money = mid;
		for(int i = 0; i < A.size(); i++) {
			if(A[i] <= money) {
				money -= A[i];
			} else if(A[i] > money) {
				money = mid - A[i];
				cnt += 1;
			}
		}
		
		if(cnt > M) {
			start = mid + 1;
		} else if(cnt <= M) {
			end = mid - 1;
			ans = mid;
		} 
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N,M;
	cin >> N >> M;
	ans = 10000;
	sum = 0;
	high = 1;
	
	for(int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
		high = max(high,tmp);
		sum += tmp;
	}
	
	Search(N,M);
	cout << ans << "\n";
	return 0;
}