#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,least;
vector<vector<int>> graph;
vector<vector<bool>> visited;
vector<pair<int,int>> virus;
queue<pair<int,int>> que;

int di[4] = {-1,1,0,0};
int dj[4] = {0,0,-1,1};

void BFS() {
	for(pair<int,int> i : virus) {
		que.push(i);
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(graph[i][j]) visited[i][j] = true;
		}
	}
	
	while(!que.empty()) {
		int i = que.front().first;
		int j = que.front().second;
		que.pop();
		
		for(int k = 0; k < 4; k++) {
			int ni = i + di[k];
			int nj = j + dj[k];
			
			if(ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
			if(visited[ni][nj]) continue;
			if(graph[ni][nj] == 1) {
				visited[ni][nj] = true;
				continue;
			}
			if(!visited[ni][nj] && graph[ni][nj] == 0) {
				que.push({ni,nj});
				visited[ni][nj] = true;
			}
		}
	}
	
	int cnt = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(!visited[i][j]) cnt += 1;
		}
	}
	//cout << cnt << "\n";
	least = max(least,cnt);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	graph.resize(N,vector<int>(M,0));
	visited.resize(N,vector<bool>(M,false));
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if(graph[i][j] == 2) {
				virus.push_back({i,j});
			}
		}
	}
	least = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(!graph[i][j]) {
				graph[i][j] = 1;
				
				bool flag1 = false;
				for(int k = i; k < N; k++) {
					int l;
					if(!flag1) {
						l = j;
						flag1 = true;
					} else l = 0;
					
					for( l ; l < M; l++) {
						if(k == i && l == j) continue;
						if(!graph[k][l]) {
							graph[k][l] = 1;
							
							bool flag2 = false;
							for(int m = k; m < N; m++) {
								int n;
								if(!flag2) {
									n = l;
									flag2 = true;
								} else n = 0;
								
								for( n ; n < M; n++) {
									if((m == k && n == l) || (m == i && n == j)) continue;
									if(!graph[m][n]) {
										graph[m][n] = 1;
										/*
										for(int a = 0; a < N; a++) {
											for(int b = 0; b < M; b++) {
												cout << graph[a][b];
											}
											cout << "\n";
										}
										cout << "\n";
										*/
										BFS();
										fill(visited.begin(),visited.end(),vector<bool>(M,false));
										graph[m][n] = 0;
									}
								}
							}
							graph[k][l] = 0;
						}
					}
				}
				graph[i][j] = 0;
			}
		}
	}
	
	cout << least << "\n";
	return 0;	
}