#include <stdio.h>

int n;
int num[11];

int max;
int maxTmp;
int maxFirst = 1;
int min;
int minTmp;
int minFirst = 1;

int bigger(int a, int b) {
	if(a > b) 
		return a;
	else 
		return b;
}

void funcMax(int cnt,int op[]) {
	if(cnt == n) {
		if(maxFirst) {
			max = maxTmp;
			maxFirst = 0;
		} else {
			max = bigger(max,maxTmp);
			//printf("max: %d\n",max);
		}
		return;
	} else {
		for(int i = 0, tmp; i < n-1; i++) {
			switch(op[i]) {
				case 1 :
					op[i] = 0;
					maxTmp += num[cnt];
					funcMax(cnt + 1,op);
					op[i] = 1;
					maxTmp -= num[cnt];
					break;
				case 2 :
					op[i] = 0;
					maxTmp -= num[cnt];
					funcMax(cnt + 1, op);
					op[i] = 2;
					maxTmp += num[cnt];
					break;
				case 3 :
					op[i] = 0;
					maxTmp *= num[cnt];
					funcMax(cnt + 1, op);
					op[i] = 3;
					maxTmp /= num[cnt];
					break;	
				case 4 : 
					tmp = maxTmp % num[cnt];
					op[i] = 0;
					maxTmp /= num[cnt];
					funcMax(cnt + 1, op);
					op[i] = 4;
					maxTmp = maxTmp * num[cnt] + tmp;
					break;
			}
		}	
	}
}

int smaller(int a, int b) {
	if(a > b)
		return b;
	else 
		return a;
}

void funcMin(int cnt,int op[]) {
	if(cnt == n) {
		if(minFirst) {
			min = minTmp;
			minFirst = 0;
		} else {
			min = smaller(min,minTmp);
			//printf("max: %d\n",max);
		}
		return;
	} else {
		for(int i = 0, tmp; i < n-1; i++) {
			switch(op[i]) {
				case 1 :
					op[i] = 0;
					minTmp += num[cnt];
					funcMin(cnt + 1,op);
					op[i] = 1;
					minTmp -= num[cnt];
					break;
				case 2 :
					op[i] = 0;
					minTmp -= num[cnt];
					funcMin(cnt + 1, op);
					op[i] = 2;
					minTmp += num[cnt];
					break;
				case 3 :
					op[i] = 0;
					minTmp *= num[cnt];
					funcMin(cnt + 1, op);
					op[i] = 3;
					minTmp /= num[cnt];
					break;	
				case 4 : 
					tmp = minTmp % num[cnt];
					op[i] = 0;
					minTmp /= num[cnt];
					funcMin(cnt + 1, op);
					op[i] = 4;
					minTmp = minTmp * num[cnt] + tmp;
					break;
			}
		}	
	}
}

int main(void) {

	int opInput[4] = {0,}; // [ + , - , * , / ]
	scanf("%d",&n);
	int op[n-1];
	
	for(int i = 0 ; i < n; i++) {
		scanf("%d",&num[i]);
	}
	
	for(int i = 0 ; i < 4; i++) {
		scanf("%d",&opInput[i]);
	}
	
	int count = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < opInput[i]; j++) {
			op[count++] = i+1;
		}
	}
	
	maxTmp = num[0];
	minTmp = num[0];
	
	funcMax(1,op);
	funcMin(1,op);
	
	printf("%d\n%d",max,min);
	
	return 0;
}