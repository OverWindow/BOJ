#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<bool> A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long min,max;
	cin >> min >> max;
	A.resize(max-min+1,true);
	long long ans = max - min + 1;
	
	for(long long i = 2; i*i <= max; i++) {
		long long temp;
		if(min%(i*i) == 0) {
			temp = min/(i*i);
		} else {
			temp = min/(i*i) + 1;
		}
		while(i*i <= (double)max/temp) {
			if(A[i*i*temp - min]) {
				A[i*i*temp - min] = false;
				ans -= 1;
			}
			//cout << i*i*temp << "\n";
			temp += 1;
		} 
	}

	cout << ans << "\n";
	return 0;
}