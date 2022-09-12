#include <stdio.h>

int sodoku[9][9] = {0,};
int finished = 0;

void dfs(int cnt) {
	if(cnt == 81) { //the end
		finished = 1;
		for(int i = 0 ; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				printf("%d ",sodoku[i][j]);
			}
			printf("\n");
		}
		return;
	}
	
	int index1 = cnt / 9;
	int index2 = cnt % 9;
	
	if(sodoku[index1][index2] != 0) {
		dfs(cnt + 1);
		return;
	}
	
	for(int num = 1; num <= 9; num++) {
		int fail = 0;
		sodoku[index1][index2] = num;
		
		int topLeftLine;
		int topLeftCol;
		if(index1 <= 2) {
			topLeftLine = 0;
		} else if (index1 <= 5) {
			topLeftLine = 3;
		} else if (index1 <= 8){
			topLeftLine = 6;
		}
		
		if(index2 <= 2) {
			topLeftCol = 0;
		} else if (index2 <= 5) {
			topLeftCol = 3;
		} else if (index2 <= 8){
			topLeftCol = 6;
		}
		
		for(int j = 0; j < 9; j++) {
			if(num == sodoku[index1][j] && j != index2) {
				fail = 1;
			}
			if(num == sodoku[j][index2] && j != index1) {
				fail = 1;
			}
		}
			
		for(int j = topLeftLine; j <= topLeftLine + 2; j++) {
			for(int k = topLeftCol; k <= topLeftCol + 2; k++) {
				if(num == sodoku[j][k] && j != index1 && k != index2) {
					fail = 1;
				}
			}
		}
		
		if(!fail) {
			dfs(cnt + 1);
			if(finished)
				return;
		} 
		sodoku[index1][index2] = 0;
		
	}
}


int main(void) {

	for(int i = 0 ; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			scanf("%d",&sodoku[i][j]);
		}
	}
	
	dfs(0);
	
	return 0;
}