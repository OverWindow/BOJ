#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin >> s;
	
	bool zero = false;
	bool sumThree = false;
	int sum = 0;
	for(int i = 0; i < s.length(); i++) {
		A.push_back(s[i] - '0');
		sum += A[i];
		if(A[i] == 0) zero = true;
	}
	if(sum % 3 == 0) sumThree = true;
	
	if(zero && sumThree) {
		sort(A.begin(),A.end());
		for(int i = A.size() - 1; i >= 0; i--) {
			cout << A[i];
		}
		cout << "\n";
	} else {
		cout << -1 << "\n";
	}
	
	return 0;
}