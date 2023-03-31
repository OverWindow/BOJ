#include <iostream>
using namespace std;

char board[2000][2000];
int boardPrefix[2001][2001];
int boardWhite[2001][2001];

int main(void) {
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	getchar();
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%c",&board[i][j]);
		}
		getchar();
	}

	int min = N*M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			// black first
			if((i+j)%2 == 0 && board[i][j] == 'B') {
				boardPrefix[i+1][j+1] = boardPrefix[i+1][j] + boardPrefix[i][j+1] - boardPrefix[i][j]+ 1;
			} else if((i+j)%2 == 1 && board[i][j] == 'W') {
				boardPrefix[i+1][j+1] = boardPrefix[i+1][j] + boardPrefix[i][j+1] - boardPrefix[i][j]+ 1;
			} else {
				boardPrefix[i+1][j+1] = boardPrefix[i+1][j] + boardPrefix[i][j+1] - boardPrefix[i][j];
			}
			
			//white first
			if((i+j)%2 == 0 && board[i][j] == 'W') {
				boardWhite[i+1][j+1] = boardWhite[i+1][j] + boardWhite[i][j+1] - boardWhite[i][j] + 1;
			} else if((i+j)%2 == 1 && board[i][j] == 'B') {
				boardWhite[i+1][j+1] = boardWhite[i+1][j] + boardWhite[i][j+1] - boardWhite[i][j] + 1;
			} else {
				boardWhite[i+1][j+1] = boardWhite[i+1][j] + boardWhite[i][j+1] - boardWhite[i][j];
			}
			
			if(i >= K-1 && j >= K-1) {
				int tmp;
				tmp=boardPrefix[i+1][j+1] - boardPrefix[i-K+1][j+1] - boardPrefix[i+1][j-K+1] + boardPrefix[i-K+1][j-K+1];
				tmp=K*K - tmp;
				if(tmp < min) min = tmp;
				
				tmp=boardWhite[i+1][j+1] - boardWhite[i-K+1][j+1] - boardWhite[i+1][j-K+1] + boardWhite[i-K+1][j-K+1];
				tmp=K*K - tmp;
				if(tmp < min) min = tmp;
			}
		}
	}
//	for(int i = 0; i < N+1; i++) {
//		for(int j = 0; j < M+1; j++) {
//			printf("%7d ",boardPrefix[i][j]);
//		}
//		printf("\n");
//	}
	printf("%d\n",min);
	return 0;
}