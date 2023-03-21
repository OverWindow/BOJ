#include <iostream>
using namespace std;

int main(void) {
	
	int N;
	cin >> N;
	
	int list[100];
	for(int i = 0; i < N; i++) {
		cin >> list[i];
	}
	
	int v;
	cin >> v;
	
	int cnt = 0;
	for(int i = 0; i < N; i++) {
		if(v == list[i]) cnt += 1;
	}
	cout << cnt << endl;
	return 0;
}