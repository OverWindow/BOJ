#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N,M,H;
vector<vector<vector<int>>> A(100,vector<vector<int>>(100,vector<int>(100,0)));
queue<pair<pair<int,int>,int>> que;

int di[6] = {-1,1,0,0,0,0};
int dj[6] = {0,0,-1,1,0,0};
int dk[6] = {0,0,0,0,-1,1};

void BFS() {
	
	while(!que.empty()) {
		int i = que.front().first.first;
		int j = que.front().first.second;
		int k = que.front().second;
		que.pop();
		
		for(int m = 0; m < 6; m++){
			int ni = i + di[m];
			int nj = j + dj[m];
			int nk = k + dk[m];
			
			if(ni < 0 || ni >= H || nj < 0 || nj >= M || nk < 0 || nk >= N) {
				continue;
			}
			if(A[ni][nj][nk] == 0) {
				A[ni][nj][nk] = A[i][j][k] + 1;
				que.push({{ni,nj},nk});
			}
		}	
	}
	return;
}

void Check() {
	int ans = -1;
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < M; j++) {
			for(int k = 0; k < N; k++) {
				ans = max(ans,A[i][j][k]);
				if(A[i][j][k] == 0) {
					cout << -1 << "\n";
					return;
				}
			}
		}
	}
	cout << ans - 1 << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> M >> H;
	bool flag = false;
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < M; j++) {
			for(int k = 0; k < N; k++) {
				cin >> A[i][j][k];
				if(A[i][j][k] == 1) {
					que.push({{i,j},k});
				} else if(A[i][j][k] == 0) {
					flag = true;
				}
			}
		}
	}
	
	if(flag) {
		BFS();
		Check();
	} else {
		cout << 0 << "\n";
	}
	
	return 0;
}