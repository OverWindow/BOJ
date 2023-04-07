#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> visited;
typedef pair<int,int> pos;

int di[4] = {-1,1,0,0};
int dj[4] = {0,0,-1,1};
int N,M;

int BFS() {
	queue<pos> que;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(graph[i][j] == 1) {
				que.push({i,j});
			}
		}
	}
	
	while(!que.empty()) {
		int i = que.front().first;
		int j = que.front().second;
		que.pop();
		
		for(int k = 0; k < 4; k++) {
			int ni = i + di[k];
			int nj = j + dj[k];
			
			if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
			if(graph[ni][nj] == -1) continue;
			if(graph[ni][nj] == 0) {
				graph[ni][nj] = graph[i][j] + 1;
				visited[ni][nj] = true;
				que.push({ni,nj});
			}
		}
	}
	int biggest = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(graph[i][j] == 0) return -1;
			biggest = max(biggest,graph[i][j]);
		}
	}
	return biggest - 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> M >> N;
	graph.resize(N,vector<int>(M,0));
	visited.resize(N,vector<bool>(M,false));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	cout << BFS() << "\n";
	return 0;
}

