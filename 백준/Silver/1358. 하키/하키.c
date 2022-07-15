#include <stdio.h> 
#include <math.h>

int main(void) 
{
	int w,h,x,y,p;
	int players[50][2];
	int inside = 0;
	
	scanf("%d %d %d %d %d",&w,&h,&x,&y,&p);
	
	for(int i = 0; i < p; i++) {
		scanf("%d %d",&players[i][0],&players[i][1]);
			
		if(pow(players[i][0] - x,2) + pow(players[i][1] - y - ((float)h/2),2) <= pow((float)h/2,2)) {
			inside += 1;
		} else if(pow(players[i][0] - x - w,2) + pow(players[i][1] - y - ((float)h/2),2) <= pow((float)h/2,2)) {
			inside += 1;
		} else if((players[i][0] >= x && players[i][0] <= x + w)&&(players[i][1] >= y && players[i][1] <= y + h)) {
			inside += 1;			
		}
	}
	
	printf("%d\n",inside);
	return 0;
}