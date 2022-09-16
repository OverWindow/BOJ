#include <stdio.h>
#include <stdlib.h>

int web[21][21][21];

int ifZero(int a, int b, int c) {
	if(a <= 0 || b <= 0 || c <= 0) {
		return 1;
	} else if (a > 20 || b > 20 || c > 20) {
		return web[20][20][20];
	} else {
		return web[a][b][c];
	}
}

void preset(void) {
	for(int i = 1; i <= 20; i++) {
		for(int j = 1; j<= 20; j++) {
			for(int k = 1; k <= 20; k++) {
				if(i < j && j < k) {
					int a,b,c;
					web[i][j][k] = ifZero(i,j,k-1) + ifZero(i,j-1,k-1) - ifZero(i,j-1,k);
				} else {
					web[i][j][k] = ifZero(i-1,j,k) + ifZero(i-1,j-1,k) + ifZero(i-1,j,k-1) - ifZero(i-1,j-1,k-1);
				}
			}
		}
	}
}


int main(void) {
	int a,b,c;
	preset();
	while(1) {
		scanf("%d %d %d",&a,&b,&c);
		if(a == -1 && b == -1 && c == -1) {
			break;
		}
		
		printf("w(%d, %d, %d) = %d\n",a,b,c,ifZero(a,b,c));
		
	}
	return 0;
}