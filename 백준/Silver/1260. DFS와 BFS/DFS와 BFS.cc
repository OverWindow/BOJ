#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

static int N,M,V;
static vector<vector<int>> A;
static vector<bool> visited;

void DFS(int node) {
	visited[node] = true;
	cout << node << " ";
	for(int i : A[node]) {
		if(!visited[i]) {
			DFS(i);
		}
	}
	return;
}

void BFS(int node) {
	queue<int> que;
	que.push(node);
	visited[node] = true;
	
	while(!que.empty()) {
		int tmp = que.front();
		cout << tmp << " ";
		que.pop();
		for(int i : A[tmp]) {
			if(!visited[i]) {
				visited[i] = true;
				que.push(i);
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> V;
	A.resize(N+1);
	
	for(int i = 0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);		
	}
	
	for(int i = 1; i <= N; i++) {
		sort(A[i].begin(),A[i].end());
	}
	
	visited = vector<bool>(N+1,false);
	DFS(V);
	cout << "\n";
	fill(visited.begin(),visited.end(),false);
	BFS(V);
	cout << "\n";
	
	return 0;
}