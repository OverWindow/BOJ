#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M;
vector<vector<int>> grid;
vector<vector<bool>> vis;

int di[4] = {-1,1,0,0};
int dj[4] = {0,0,-1,1};

void BFS(int si,int sj) {
	queue<pair<int,int>> que;
	que.push({si,sj});
	vis[si][sj] = true;
	
	while(!que.empty()) {
		int i = que.front().first;
		int j = que.front().second;
		que.pop();
		
		for(int k = 0; k < 4; k++) {
			int ni = i + di[k];
			int nj = j + dj[k];
			
			if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
			if(vis[ni][nj]) continue;
			if(grid[ni][nj] != 0 && vis[ni][nj] == false) {
				vis[ni][nj] = true;
				que.push({ni,nj});
			}
		}
	}
	return;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	grid.resize(N,vector<int>(M,0));
	vis.resize(N,vector<bool>(M,false));
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> grid[i][j];
			
		}
	}
	
	int result = 0;
	while(true) {
		// IceBerg Melt
		vector<vector<int>> tmp;
		tmp.resize(300,vector<int>(300,0));
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(grid[i][j] == 0) continue;
				
				int cnt = 0;
				for(int k = 0; k < 4; k++) {
					int ni = i + di[k];
					int nj = j + dj[k];
					if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
					if(grid[ni][nj] == 0) cnt += 1;
				}
				
				tmp[i][j] = max(0,grid[i][j] - cnt);
			}
		}
		result += 1;
		grid = tmp;
//		for(int i = 0; i < N; i++) {
//			for(int j = 0; j < M; j++) {
//				cout << grid[i][j];
//			}
//			cout << "\n";
//		}
//		break;

		// IceBerg Check
		int IceBerg = 0;
		int cnt = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(grid[i][j] == 0) {
					cnt += 1;
					continue;
				}
				if(vis[i][j] == true) continue;
				IceBerg += 1;
//				cout << IceBerg << "\n";
				BFS(i,j); 
			}
		}
		if(IceBerg >= 2) {
			break;
		}
		if(cnt == N * M) {
			cout << 0 << "\n";
			return 0;
		}
		
		// Reset
		fill(vis.begin(),vis.end(),vector<bool>(M,false));
	}
	
	cout << result << "\n";
	return 0;
}