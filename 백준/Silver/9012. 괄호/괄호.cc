#include <iostream>
#include <stack>
using namespace std;

string check(string ps) {
	stack<int> stk;
	for(int j = 0; j < ps.size(); j++) {
		if(ps[j] == '(') {
			stk.push(1);
		} else if(ps[j] == ')') {
			if(stk.empty()) {
				return "NO";
				break;
			} else {
				stk.pop();
			}
		}
	}
	if(stk.empty()) return "YES";
	else return "NO";
}


int main(void) {
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;

	for(int i = 0; i < N; i++) {
		string ps;
		cin >> ps;
		cout << check(ps) << endl;
	}
	return 0;
}