#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int K;
	cin >> K;
	
	stack<int> stk;
	for(int i = 0; i < K; i++) {
		int tmp;
		cin >> tmp;
		
		if(tmp != 0) {
			stk.push(tmp);
		} else if (tmp == 0 && !stk.empty()) {
			stk.pop();
		}
	}
	
	if(stk.empty()) {
		cout << 0 << "\n";
	} else {
		int sum = 0;
		while(!stk.empty()) {
			sum += stk.top();
			stk.pop();
		}
		cout << sum << "\n";
	}
	
	return 0;
}