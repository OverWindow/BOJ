#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> vis;
vector<int> result;
int M,N,K;
int size_;
int di[4] = {-1,1,0,0};
int dj[4] = {0,0,-1,1};

void DFS(int i, int j) {
	if(vis[i][j] == true) {
		return;
	}
	vis[i][j] = true;
	size_ += 1;
	for(int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		
		if(ni >= N || ni < 0 || nj >= M || nj < 0) {
			continue;
		}
		
		if(grid[ni][nj] == 0 && vis[ni][nj] == false) {
			DFS(ni,nj);
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	grid.resize(100,vector<int>(100,0));
	vis.resize(100,vector<bool>(100,false));
	
	cin >> M >> N >> K;
	
	for(int i = 0; i < K; i++) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		for(int j = a; j < c; j++) {
			for(int k = b; k < d; k++) {
				grid[j][k] = 1;
			}
		}
	}

//	for(int i = 0; i < N; i++) {
//		for(int j = 0; j < M; j++) {
//			cout << grid[i][j] << " ";
//		}
//		cout << "\n";
//	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(grid[i][j] == 0 && vis[i][j] == false) {
				size_ = 0;
				DFS(i,j);
				result.push_back(size_);
			}
		}
	}
	
	sort(result.begin(),result.end());
	
	cout << result.size() << "\n";
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}