#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 11724 BFS

vector<vector<int>> A;
vector<bool> visited;
int N,M;

void BFS(int start) {
	visited[start] = true;
	queue<int> que;
	que.push(start);
	
	while(!que.empty()) {
		int cur = que.front();
		que.pop();
		
		for(int i : A[cur]) {
			if(!visited[i]) {
				que.push(i);
				visited[i] = true;
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	visited.resize(N+1,false);
	A.resize(N+1);
	for(int i = 0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}
	
	int cnt = 0;
	for(int i = 1; i <= N; i++) {
		if(!visited[i]) {
			BFS(i);
			cnt += 1;
		}
	}
	cout << cnt << "\n";
	return 0;
}