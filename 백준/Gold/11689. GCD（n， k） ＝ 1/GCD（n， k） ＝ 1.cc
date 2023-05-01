#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long N;
	cin >> N;
	
	long long ans = N;
	for(long long i = 2; i*i <= N; i++) {
		if(N%i == 0) {
			ans = ans - ans/i;
		}
		while(N%i == 0) { 
			N = N/i;
		}
	}
	
	// 루트 N보다 큰 소인수는 1개  혹은 0개이다 
	if(N>1) {
		ans = ans - ans/N;
	}
	cout << ans; 
	return 0;
}