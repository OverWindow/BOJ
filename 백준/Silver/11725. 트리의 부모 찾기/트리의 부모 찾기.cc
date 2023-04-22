#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N;
vector<vector<int>> A;
vector<bool> vis;
vector<int> mother;

void DFS(int cur) {
	vis[cur] = true;
	for(int i = 0; i < A[cur].size(); i++) {
		int target = A[cur][i];
		if(vis[target] == false) {
			mother[target] = cur;
			DFS(target);
		}
	}
	vis[cur] = false;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	A.resize(N+1,vector<int>(0,0));
	vis.resize(N+1,false);
	mother.resize(N+1,0);
	for(int i = 0; i < N - 1; i++) {
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}
	
	DFS(1);
	
	for(int i = 2; i <= N; i++) {
		cout << mother[i] << "\n";
	}
	return 0;
}