#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	stack<int> stk;
	
	for(int i = 0; i < N; i++) {
		string command;
		cin >> command;
		
		if(command.compare("push") == 0){
			int node;
			cin >> node;
			stk.push(node);
		} else if(command.compare("top") == 0) {
			if(stk.empty()) cout << "-1" << endl;
			else cout << stk.top() << endl;
		} else if(command.compare("pop") == 0) {
			if(stk.empty()) {
				cout << "-1" << endl;
			} else {
				cout << stk.top() << endl;
				stk.pop();
			}
		} else if(command.compare("size") == 0) {
			cout << stk.size() << endl;
		} else if(command.compare("empty") == 0) {
			if(stk.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	return 0; 	
}