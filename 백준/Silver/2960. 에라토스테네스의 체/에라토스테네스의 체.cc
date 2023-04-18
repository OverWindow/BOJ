#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N,K;
	cin >> N >> K;
	
	vector<bool> A(N + 1,true);
	int cnt = 0;
	int ans = 0;
	for(int i = 2; i <= N; i++) {
		for(int j = i; j <= N; j+=i) {
			if(A[j]) {
				A[j] = false;
				cnt += 1;
			}
			if(cnt == K) {
				ans = j;
				break;
			}
		}
		if(ans) break;
	}
	cout << ans << "\n";
	return 0;
}