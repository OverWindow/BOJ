#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
long long N,K,ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	cin >> K;
	
	long long i = 1;
	long long j = K;
	
	while(i <= j) {
		long long mid = (i + j)/2;
		
		long long cnt = 0;
		long long same = 0;
		for(int k = 1; k <= N; k++) {
			cnt += min(mid/k,N);
			if(mid%k == 0 && mid/k <= N) same += 1;
		}
		//cout << mid << "\n";
		
		if(cnt - same + 1 <= K && K <= cnt) {
			//cout << cnt << " " << same << "\n";
			ans = mid;
			break;
		} else if(cnt < K) {
			i = mid + 1;
		} else if(K < cnt - same + 1) {
			j = mid - 1;
		}
	}
	
	cout << ans << "\n";
	return 0;
}