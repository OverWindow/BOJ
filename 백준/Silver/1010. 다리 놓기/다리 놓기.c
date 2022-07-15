#include <stdio.h>

int Pascal_Triangle[35][35] = {0};

int main(void) 
{
	int t;
	scanf("%d",&t);
	
	Pascal_Triangle[0][0]= 1;
	for(int i = 0; i <= 31; i++) {
		Pascal_Triangle[i][0] = 1;
		for(int j = 0; j <= i; j++) {
			if(Pascal_Triangle[i-1][j] > 0) {
				Pascal_Triangle[i][j] = Pascal_Triangle[i-1][j-1] + Pascal_Triangle[i-1][j];
			} else {
				Pascal_Triangle[i][j] = 1;
			}
		}
	}
	
	for(int i = 0 ; i < t; i++) {
		int n,m;
		scanf("%d %d",&n,&m);
		printf("%d\n",Pascal_Triangle[m][n]);
	}
	
	return 0;
}