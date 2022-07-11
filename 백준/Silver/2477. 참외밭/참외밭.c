#include <stdio.h> 

int main(void) 
{
	int melon;
	int walls[12][2] = {0};
	int wallstack[5] = {0};
	
	int big_rectangle = 1;
	int small_rectangle;
	
	scanf("%d",&melon);	
	
	for(int i = 0; i < 6; i++) {
		scanf("%d %d",&walls[i][0],&walls[i][1]);
		wallstack[walls[i][0]] += 1;
		walls[i+6][0] = walls[i][0];
		walls[i+6][1] = walls[i][1];
	}
	
	for(int i= 0; i < 6; i++) {
		if (wallstack[walls[i][0]] == 1) {
			big_rectangle *= walls[i][1];
		}
	}
	
	
	for(int i = 0; i < 12; i++) {
		if(walls[i][0] == walls[i+2][0] && walls[i+1][0] == walls[i+3][0]) {
			small_rectangle = walls[i+1][1] * walls[i+2][1];
			break;
		}	
	}
	
	printf("%d\n",(big_rectangle-small_rectangle)*melon);
	return 0;
}