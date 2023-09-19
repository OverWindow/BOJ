#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N,M;
vector<pair<int,int>> route;
int grid[501][501];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for(int i = 0; i <= N; i++) {
		for(int j = 0; j <= N; j++) {
			if(i == j) grid[i][j] = 0;
			else grid[i][j] = INF;
		}
	}	
	
	for(int i = 0; i < M ;i++) {
		int a,b;
		cin >> a >> b;
		grid[a][b] = 1;
	}
	
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
			}
		}
	}
	
	int cnt = 0;
	for(int i = 1; i<= N; i++) {
		int tmp = 0;
		for(int j = 1; j <= N; j++) {
			if(i == j) continue;
			if(grid[i][j] != INF || grid[j][i] != INF) {
				tmp += 1;
			}
		}
		if(tmp == N - 1) {
			cnt += 1;
		}
	}
	
	cout << cnt << "\n";
	return 0;
}