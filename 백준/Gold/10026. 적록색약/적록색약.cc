#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<char>> normal;
vector<vector<bool>> visited;
int di[4] = {-1,1,0,0};
int dj[4] = {0,0,-1,1};

void DFS(int i, int j, char x) {
	if(normal[i][j] != x || visited[i][j]) {
		return;
	}
	visited[i][j] = true;
	for(int k = 0; k < 4; k++) {
		int ni = i + di[k];
		int nj = j + dj[k];
		
		if(ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
		if(visited[ni][nj]) continue;
		if(normal[ni][nj] == x && !visited[ni][nj]) {
			DFS(ni,nj,x);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	normal.resize(N,vector<char>(N,'0'));
	visited.resize(N,vector<bool>(N,false));
	
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < N; j++) {
			normal[i][j] = s[j]; 
		}
	}
	
	int a = 0;
	int b = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(!visited[i][j]) {
				DFS(i,j,normal[i][j]);
				a += 1;
			}
		}
	}
	fill(visited.begin(),visited.end(),vector<bool>(N,false));
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(normal[i][j] == 'G') normal[i][j] = 'R';
		}
	}	
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(!visited[i][j]) {
				DFS(i,j,normal[i][j]);
				b += 1;
			}
		}
	}	
	cout << a << " " << b << "\n";
	return 0;	
}