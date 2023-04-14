#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<vector<int>> A;
vector<vector<int>> vis;

int di[4] = {-1,1,0,0};
int dj[4] = {0,0,-1,1};

int DFS(int i,int j) {
	if(i == N -1 && j == M -1) {
		return 1;
	} else if(vis[i][j] != -1) {
		return vis[i][j];
	}
	
	vis[i][j] = 0;
	for(int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		
		if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
		if(A[ni][nj] < A[i][j]) {
			vis[i][j] += DFS(ni,nj);
		}
	}
	return vis[i][j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M;
	A.resize(N,vector<int>(M,0));
	vis.resize(N,vector<int>(M,-1));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	
	cout << DFS(0,0) << "\n";
	
//	for(int i = 0; i < N; i++) {
//		for(int j = 0; j < M; j++) {
//			cout << vis[i][j];
//		}
//		cout << "\n";
//	}
	return 0;
}