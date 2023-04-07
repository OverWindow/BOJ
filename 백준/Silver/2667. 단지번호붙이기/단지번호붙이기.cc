#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector<vector<int>> grid;
static vector<vector<int>> visited;
static vector<int> house;

void DFS(int i, int j, int cnt,int N) {
	if(grid[i][j] == 0 || visited[i][j] == 1) {
		return;
	}
	visited[i][j] = 1;
	house[cnt] += 1;
	// north
	if(i != 0) {
		DFS(i-1,j,cnt,N);
	}
	// east
	if(j != N-1) {
		DFS(i,j+1,cnt,N);
	} 
	// south
	if(i != N-1) {
		DFS(i+1,j,cnt,N);
	} 
	// west
	if(j != 0) {
		DFS(i,j-1,cnt,N);
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	grid.resize(N,vector<int>(N,0));
	visited.resize(N,vector<int>(N,0));
	
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < N; j++) {
			if(s[j] == '0') grid[i][j] = 0;
			else if(s[j] == '1') grid[i][j] = 1;
		}
	}
	
	int cnt = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(grid[i][j] == 0) continue;
			if(visited[i][j]) continue;
			if(grid[i][j] == 1) {
				house.push_back(0);
				DFS(i,j,cnt,N);
				cnt += 1;
			}
		}
	}
	cout << cnt << "\n";
	sort(house.begin(),house.end());
	for(int i : house) {
		cout << i << "\n";
	}
	return 0;
}