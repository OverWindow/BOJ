#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N,M;
int d[401][401];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j <= N; j++) {
			if(i==j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}
	
	for(int i = 0; i < M; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		
		d[a][b] = c;
	}
	
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	
	int res = INF * 2;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(i == j) continue;
			if(d[i][j] == INF || d[j][i] == INF) continue;
			res = min(res,d[i][j] + d[j][i]);
//			cout << d[i][j] << " ";
		}
//		cout << "\n";
	}
	
	if(res == INF * 2) cout << -1 << "\n";
	else cout << res << "\n";
	return 0;
}