#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
vector<int> cities;

int find(int cur) {
	if(cur == cities[cur]) {
		return cur;
	}
	cities[cur] = find(cities[cur]);
	return cities[cur];
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);
	
	if(a > b) swap(a,b);
	
	cities[b] = a;
	return;
}

int main(void) {
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	cin >> M;
	
	// reset
	cities.resize(N+1,0);
	for(int i = 0; i <= N; i++) {
		cities[i] = i;
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			
			if(tmp == 0) continue;
			
			uni(i,j);
		}
	}
	
	int rep;
	cin >> rep;
	rep = find(rep);
	
	for(int i = 0; i < M - 1; i++) {
		int tmp;
		cin >> tmp;
		tmp = find(tmp);
		
		if(rep != tmp) {
			cout << "NO\n";
			return 0;
		}
	}
	
	cout << "YES\n";
	return 0;
}