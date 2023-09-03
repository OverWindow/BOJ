#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int K,W,H;
int grid[200][200];
bool vis[200][200][31];
int result[200][200];

int di[4] = {-1,1,0,0};
int dj[4] = {0,0,-1,1};

int dhi[8] = {-2,-1,1,2,2,1,-1,-2};
int dhj[8] = {1,2,2,1,-1,-2,-2,-1};

typedef struct {
	int x;
	int y;
	int count;
	int horse;
}newstand;

void BFS(int si, int sj) {
	queue<newstand> que;
	que.push({si,sj,0,0});
	
	vis[0][0][0] = true;
	while(!que.empty()) {
		int i = que.front().x;
		int j = que.front().y;
		int count = que.front().count;
		int horse = que.front().horse;
		que.pop();
		
		if(i == H - 1 && j == W - 1) {
			cout << count << "\n";
			return;
		}
		
		if(horse < K) {
			for(int k = 0; k < 8; k++) {
				int ni = i + dhi[k];
				int nj = j + dhj[k];
				
				if(ni < 0 || ni >= H || nj < 0 || nj >= W) {
					continue;
				}
				
				if(grid[ni][nj] == 0 && vis[ni][nj][horse+1] == false) {
					vis[ni][nj][horse + 1] = true;
					que.push({ni,nj,count+1,horse+1});
				}	
			}
		}
		
		for(int k = 0; k < 4; k++) {
			int ni = i + di[k];
			int nj = j + dj[k];
			
			if(ni < 0 || ni >= H || nj < 0 || nj >= W) {
				continue;
			}
			
			if(grid[ni][nj] == 0 && vis[ni][nj][horse] == false) {
				vis[ni][nj][horse] = true;
				que.push({ni,nj,count+1,horse});
			}
		}
	}
	
	cout << -1 << "\n";
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> K;
	cin >> W >> H;
	
	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			cin >> grid[i][j];
		}
	}
	
	BFS(0,0);
	
	return 0;
}