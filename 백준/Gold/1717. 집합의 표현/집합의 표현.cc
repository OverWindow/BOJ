#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1717 Union Find

int N,M;
vector<int> parent;

int find(int cur) {
	if(cur == parent[cur]) {
		return cur;
	}
	parent[cur] = find(parent[cur]);
	return parent[cur];
}

void uni(int a, int b) {
	int aRep = find(a);
	int bRep = find(b);
	
	if(aRep > bRep) {
		swap(aRep,bRep);
	}
	
	parent[bRep] = aRep;
	return;
}

bool inspect(int a,int b) {
	int aRep = find(a);
	int bRep = find(b);
	
	if(aRep == bRep) {
		return true;
	} else {
		return false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	// list reset 
	parent.resize(N+1,0);
	for(int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	
	for(int i = 0; i < M; i++) {
		int op,a,b;
		cin >> op >> a >> b;
		
		if(op == 0) {
			uni(a,b);
		} else if (op == 1) {
			if(inspect(a,b)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}		
	}
	return 0;
}