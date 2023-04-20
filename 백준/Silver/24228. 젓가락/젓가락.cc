#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long N,R;
	cin >> N >> R;
	cout << N + 2 * R  - 1<< "\n";
	return 0;
}