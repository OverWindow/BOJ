#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N,M;
int dis[101][101];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	cin >> M;
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(i == j) dis[i][j] = 0;
			else dis[i][j] = INF;
		}
	}
	
	for(int i = 0; i < M; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		
		dis[a][b] = min(dis[a][b],c);
	}	
	
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
			}
		}
	}
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1;j <= N; j++) {
			if(dis[i][j] == INF) cout << 0 << " ";
			else cout << dis[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}