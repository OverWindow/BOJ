#include <stdio.h>
#include <stdlib.h>
int N;
int grid[20][20];
int playerList[20];
int min;
int flag = 1;

void playerSort(int cnt, int start) {
	if ( cnt == N/2) {
		int teamA[10] = {0,};
		int teamB[10] = {0,};
		int teamApoint = 0;
		int teamBpoint = 0;
		int Btmp = 0;
		int Atmp = 0;
		for(int i = 0 ; i < N; i++) {
			if(playerList[i]) {
				teamB[Btmp] = i+1;
				Btmp += 1;
			} else {
				teamA[Atmp] = i+1;
				Atmp += 1;
			}
		}
		/*
		for(int i = 0 ; i < N/2; i++) {
			printf("%d ",teamA[i]);
		}
		for(int i = 0; i < N/2; i++) {
			printf("%d ",teamB[i]);
		}
		printf("\n"); */
		for(int i = 0 ; i < N/2; i++) {
			for(int j = 0 ; j < N/2; j++) {
				if(i != j) {
					teamApoint += grid[teamA[i]-1][teamA[j]-1];
					teamBpoint += grid[teamB[i]-1][teamB[j]-1];
				}
			}
		}
	

		int tmp = abs(teamApoint - teamBpoint);	
		if(flag) {
			min = tmp;
			flag = 0;
		} else if(tmp < min) {
			min = tmp;
		}
		teamApoint = 0;
		teamBpoint = 0;
		return;
	
	} else {
		for(int i = start; i < N; i++) {
			if(playerList[i]) {
				playerList[i] = 0;
				playerSort(cnt+1,i+1);
				playerList[i] = 1;
			}
		}
	}
}

int main(void) {
	scanf("%d",&N);	

	for(int i = 0 ; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d",&grid[i][j]);
		}
		playerList[i] = 1;
	}
	
	playerSort(0,0); 
	
	printf("%d\n",min);
	return 0;
}