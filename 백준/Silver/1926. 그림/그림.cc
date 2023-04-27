#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
int cnt,biggest,tmp;
vector<vector<int>> graph;
vector<vector<bool>> vis;
int di[4] = {-1,1,0,0};
int dj[4] = {0,0,-1,1};

void DFS(int i, int j) {
	vis[i][j] = true;
	tmp += 1;
	for(int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		
		if(ni < 0 || ni >= N || nj < 0 || nj >= M) {
			continue;
		}
		if(!vis[ni][nj] && graph[ni][nj] == 1) {
			DFS(ni,nj);
		}
	}
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	graph.resize(N,vector<int>(M,0));
	vis.resize(N,vector<bool>(M,false));
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}
	
	cnt = 0;
	biggest = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(!vis[i][j] && graph[i][j] == 1) {
				cnt += 1;
				DFS(i,j);
				biggest = max(biggest,tmp);
				tmp = 0;
			}
		}
	}
	
	cout << cnt << "\n" << biggest << "\n";
	return 0;
}