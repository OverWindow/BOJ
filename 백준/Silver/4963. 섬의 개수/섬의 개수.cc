#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> visited;
int di[8] = {-1,-1,-1,0,0,1,1,1};
int dj[8] = {-1,0,1,-1,1,-1,0,1};
int N,M;

void DFS(int i, int j) {
	if(graph[i][j] == 0 || visited[i][j]) {
		return;
	}
	visited[i][j] = true;
	for(int k = 0; k < 8; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		
		if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
		
		if(!visited[ni][nj] && graph[ni][nj] == 1) {
			DFS(ni,nj);
		}
	}
	return;
}
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	graph.resize(50,vector<int>(50,0));
	visited.resize(50,vector<bool>(50,false));
	while(true) {
		cin >> M >> N;
		if(M == 0 && N == 0) break;
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				cin >> graph[i][j];
			}
		}
		
		int cnt = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(!visited[i][j] && graph[i][j] == 1) {
					DFS(i,j);
					cnt += 1;
				}
			}
		}
		cout << cnt << "\n";
		fill(graph.begin(),graph.end(),vector<int>(M,0));
		fill(visited.begin(),visited.end(),vector<bool>(M,false));
	}
	return 0;	
}