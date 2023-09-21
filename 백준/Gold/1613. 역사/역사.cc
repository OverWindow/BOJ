#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N,M,S;
int going[401][401];
int backward[401][401];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(i == j) {
				going[i][j] = 0;
				backward[i][j] = 0;
			} else {
				going[i][j] = INF;
				backward[i][j] = INF;	
			}
		}
	}
		
	for(int i = 0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		
		going[a][b] = 1;
		backward[b][a] = 1;
	}
	
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				going[i][j] = min(going[i][j], going[i][k] + going[k][j]);
				backward[i][j] = min(backward[i][j], backward[i][k] + backward[k][j]);
			}
		}
	}
	
	cin >> S;
	
	for(int i = 0; i < S; i++) {
		int a,b;
		cin >> a >> b;

		if(going[a][b] == INF && backward[a][b] == INF) {
			cout << 0 << "\n";
		} else if (going[a][b] != INF && backward[a][b] == INF) {
			cout << -1 << "\n";
		} else if (going[a][b] == INF && backward[a][b] != INF) {
			cout << 1 << "\n";
		}
	}
	
	return 0;
}