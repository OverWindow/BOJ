#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int R,C,greatest;
vector<vector<int>> graph;
vector<bool> visited;

int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1};

void DFS(int i, int j, int stage) {
	if(visited[graph[i][j]]) {
		return;
	}
	visited[graph[i][j]] = true;
	for(int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		
		if(ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
		if(!visited[graph[ni][nj]]) {
			//cout << (char)('A' + graph[ni][nj]) << "\n";
			DFS(ni,nj,stage + 1);
			greatest = max(greatest,stage + 1);
		}
	}
	visited[graph[i][j]] = false;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> R >> C;
	graph.resize(R,vector<int>(C,0));
	visited.resize(20,false);
	greatest = 1;
	for(int i =0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			char tmp;
			cin >> tmp;
			//cout << (int)(tmp - 'A');
			graph[i][j] = (int)(tmp - 'A');
		}
		//cout << "\n";
	}
	
	DFS(0,0,1);
	
	cout << greatest << "\n";
	return 0;
}