#include <stdio.h>
#include <math.h>

int main(void) 
{
	int test_case;
	
	scanf("%d",&test_case);
	
	int start_x,start_y, end_x, end_y;
	int circle_num;
	int circles[50][3];
	
	for(int test = 0; test < test_case; test++) {
		
		int inside_and_out = 0;
		scanf("%d %d %d %d",&start_x, &start_y, &end_x, &end_y);
		scanf("%d",&circle_num);
		
		for(int i = 0; i < circle_num; i++) {
			scanf("%d %d %d",&circles[i][0],&circles[i][1],&circles[i][2]);
			
			int flag = 0;
			if(pow(circles[i][0] - start_x,2) + pow(circles[i][1] - start_y,2) <= pow(circles[i][2],2)) {
				inside_and_out += 1;
				flag += 1;
			}
			if(pow(circles[i][0] - end_x,2) + pow(circles[i][1] - end_y,2) <= pow(circles[i][2],2)) {
				inside_and_out += 1;
				if(flag == 1) {
					inside_and_out -= 2;
				}
			}
		}
		
		printf("%d\n",inside_and_out);
	}
	
	return 0;
}