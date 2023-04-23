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
	
	long long total = A * B;
	
	if(A<B) swap(A,B);
	while(1) {
		long long tmp;
		tmp = A;
		A = B;
		B = tmp%B;
		if(B == 0) break;
	}
	
	cout << total/A << "\n";
	return 0;
}