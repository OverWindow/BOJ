#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long A,B;
	cin >> A >> B;

	while(1) {
		long long tmp;
		tmp = A;
		A = B;
		B = tmp%B;
		if(B == 0) break;
	}
	
	for(long long i = 0; i < A; i++) {
		cout << 1;
	}
	cout << "\n";
	return 0;
}