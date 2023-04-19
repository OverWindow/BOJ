#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> board;
int di[8] = {-2,-1,1,2,2,1,-1,-2};
int dj[8] = {1,2,2,1,-1,-2,-2,-1};

void BFS(int I, int si,int sj,int ei, int ej) {
	queue<pair<int,int>> que;
	que.push({si,sj});
	board[si][sj] = 1;
	
	while(!que.empty()) {
		int i = que.front().first;
		int j = que.front().second;
		que.pop();
		
		if(i == ei && j == ej) {
			while(!que.empty()) que.pop();
			break;
		}
		
		for(int k = 0; k < 8; k++) {
			int ni = i + di[k];
			int nj = j + dj[k];
			
			if(ni < 0 || ni >= I || nj < 0 || nj >= I) continue;
			if(board[ni][nj] == 0) {
				board[ni][nj] = board[i][j] + 1;
				que.push({ni,nj});
			} 
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	board.resize(300,vector<int>(300,0));
	for(int i = 0; i < T; i++) {
		int I,si,sj,ei,ej;
		cin >> I;
		fill(board.begin(),board.end(),vector<int>(I,0));
		cin >> si >> sj;
		cin >> ei >> ej;
		
		BFS(I,si,sj,ei,ej);
/*		for(int j = 0; j < I; j++) {
			for(int k = 0; k < I; k++) {
				cout << board[j][k] << " ";
			}
			cout << "\n";
		}*/
		
		cout << board[ei][ej] - 1 << "\n";
	}
	
	return 0;
}