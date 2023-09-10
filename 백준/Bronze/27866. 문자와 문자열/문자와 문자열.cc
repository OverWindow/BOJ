#include <iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	cin >> s;
	 
	int N;
	cin >> N;
	
	cout << s[N-1] << "\n";
	return 0;
}