#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

typedef struct {
	int x;
	int y;
	int wall;
}newstand;

int N,M;
int grid[1001][1001];
int result[1001][1001];
bool vis[1001][1001][2];
int di[4] = {-1,1,0,0};
int dj[4] = {0,0,-1,1};

void BFS(int si,int sj) {
	queue<newstand> que;
	que.push({si,sj,0});
	result[1][1] = 1;
	vis[1][1][0] = true;
	
	while(!que.empty()) {
		int i = que.front().x;
		int j = que.front().y;
		int wall = que.front().wall;
		que.pop();
		
		for(int k = 0; k < 4; k++) {
			int ni = i + di[k];
			int nj = j + dj[k];
			
			if(ni < 1 || ni > N || nj < 1 || nj > M) {
				continue;
			}
			// wall and not visited
			if(grid[ni][nj] == 1 && wall == 0 && vis[ni][nj][wall + 1] == false) {
				result[ni][nj] = result[i][j] + 1;
				vis[ni][nj][wall + 1] = true;
				que.push({ni,nj,wall + 1});
			}
			
			// not wall and not visited
			if(grid[ni][nj] == 0 && vis[ni][nj][wall] == false) {
				result[ni][nj] = result[i][j] + 1;
				vis[ni][nj][wall] = true;
				que.push({ni,nj,wall});
			}
			
			if(ni == N && nj == M) {
				cout << result[ni][nj] << "\n";
				return;
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

	for(int i = 1; i <= N; i++) {
		string tmp;
		cin >> tmp;
		for(int j = 1; j <= M; j++) {
			grid[i][j] = tmp[j-1] - '0';
		}
	}
	
	BFS(1,1);
	
//	for(int i = 1; i <= N; i++) {
//		for(int j = 1; j <= M; j++) {
//			cout << result[i][j];
//		}
//		cout << "\n";
//	}


	if (N==1 && M==1) cout << 1 << "\n";
	else if (result[N][M] == 0) cout << -1 << "\n";
	return 0;
}