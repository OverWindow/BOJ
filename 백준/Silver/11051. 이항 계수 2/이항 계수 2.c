#include <stdio.h> 

int Pascal_Triangle[1001][1001] = {0};

int main(void) 
{
	int n , k;
	
	scanf("%d %d",&n,&k);
	
	Pascal_Triangle[0][0] = 1;
	for(int i = 1; i < 1001; i++ ) {
		Pascal_Triangle[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			if(Pascal_Triangle[i-1][j] > 0) {
				Pascal_Triangle[i][j] = (Pascal_Triangle[i-1][j] + Pascal_Triangle[i-1][j-1])%10007;
			} else {
				Pascal_Triangle[i][j] = 1;
			}
		}
	}
	
	printf("%d\n",Pascal_Triangle[n][k]);
	
	/*
	for(int i = 0; i< 100; i++) {
		for(int j = 0; j <= i; j++) {
			printf("%d ",Pascal_Triangle[i][j]);
		}
		printf("\n");
	}
	*/
	
	return 0;
}