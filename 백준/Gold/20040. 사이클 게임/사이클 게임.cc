#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
vector<int> dots;

int find(int cur) {
	if(cur == dots[cur]) {
		return cur;
	}
	dots[cur] = find(dots[cur]);
	return dots[cur];
}

bool uni(int a,int b) {
	a = find(a);
	b = find(b);
	
	if(a > b) swap(a,b);
	
	if(a == b) {
		return true;
	} else {
		dots[b] = a;
		return false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	dots.resize(N,0);
	for(int i = 0; i < N; i++) {
		dots[i] = i;
	}
	
	for(int i = 0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		
		if(uni(a,b) && i >= 2) {
			cout << i + 1 << "\n";
			return 0;
		}
	}
//	
//	for(int i = 0; i < N; i++) {
//		cout << dots[i] << " ";
//	}
	
	cout << 0 << "\n";
	return 0;	
}