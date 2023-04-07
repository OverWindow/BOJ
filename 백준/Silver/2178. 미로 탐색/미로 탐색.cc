#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int N,M,least;
typedef pair<int,int> pos;
static vector<vector<int>> maze;
static vector<vector<bool>> visited;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void BFS(int i, int j) {
	visited[i][j] = true;
	
	queue<pos> que;
	que.push(pos(0,0));
	
	while(!que.empty()) {
		pos tmp = que.front();
		int i = tmp.first;
		int j = tmp.second;
		que.pop();
		for(int k = 0; k < 4; k++) {
			int ni = i + dx[k];
			int nj = j + dy[k];
			
			if(ni < 0 || ni >= N || nj < 0 || nj >= M) {
				continue;
			} 
			
			if(maze[ni][nj] == 0) {
				continue;
			}
			
			if(maze[ni][nj] == 1 && visited[ni][nj] == false) {
				visited[ni][nj] = true;
				maze[ni][nj] = maze[i][j] + 1;
				que.push(pos(ni,nj));
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
	maze.resize(N,vector<int>(M,0));
	visited.resize(N,vector<bool>(M,false));
	
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < M; j++) {
			if(s[j] == '1') {
				maze[i][j] = 1;
			} else if(s[j] == '0') {
				maze[i][j] = 0;
			}
		}
	}
	
	BFS(0,0);
	
	cout << maze[N-1][M-1] << "\n";
	return 0;	
}