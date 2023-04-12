#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N,greatest;
vector<vector<int>> graph;
vector<vector<bool>> visited;

int di[4] = {-1,1,0,0};
int dj[4] = {0,0,-1,1};

void BFS(int i, int j, int water) {
	visited[i][j] = true;
	queue<pair<int,int>> que;
	que.push({i,j});
	
	while(!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		
		for(int k = 0; k < 4; k++) {
			int ni = x + di[k];
			int nj = y + dj[k];
			
			if(ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
			if(visited[ni][nj] || graph[ni][nj] <= water) continue;
			if(!visited[ni][nj] && graph[ni][nj] > water) {
				visited[ni][nj] = true;
				que.push({ni,nj});
			}
		}
	} 	
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	greatest = 0;
	graph.resize(N,vector<int>(N,0));
	visited.resize(N,vector<bool>(N,false));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	
	for(int i = 0;i <= 100; i++) {
		int cnt = 0;
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < N; k++) {
				if(!visited[j][k] && graph[j][k] > i) {
					cnt += 1;
					BFS(j,k,i);	
				}
			}
		}
		fill(visited.begin(),visited.end(),vector<bool>(N,false));
		greatest = max(greatest,cnt);
	} 
	
	cout << greatest << "\n";
	return 0;
}