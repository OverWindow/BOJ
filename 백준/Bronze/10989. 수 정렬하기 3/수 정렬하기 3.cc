#include <iostream>
using namespace std;

int a[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		a[tmp] += 1; 
	}
	
	for(int i = 0; i < 10001; i++) {
		while(a[i]) {
			cout << i << "\n";
			a[i]--;
		}
	}
	return 0;
}