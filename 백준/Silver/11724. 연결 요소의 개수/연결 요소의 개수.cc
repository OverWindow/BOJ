#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<vector<int>> A;
vector<bool> visited;

void DFS(int cur) {
	if(visited[cur] == true) {
		return;
	}
	visited[cur] = true;
//	cout << "hoh" << cur << endl;
	for(int i : A[cur]) {
//		cout << "hello: " << i << endl;
		if(visited[i] == false) {
			DFS(i);
		}	
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	A.resize(N+1);
	visited.resize(N+1,false);
	
	for(int i = 0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);	
	}
	
	int cnt = 0;
	for(int i = 1; i <= N; i++) {
		if(visited[i] == false) {
			DFS(i);
			cnt += 1;
		}
	}
	
	cout << cnt << endl;
	return 0;
}