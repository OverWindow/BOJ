#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INFINITE 1000000000

int city;
int cities[1001];
int fastest[1001];
int bus;
int route[100000][3];
int start, end;
int min(int,int);

int dijkstra(void) {
	for(int i = 1; i <= city; i++) {
		fastest[i] = INFINITE;
		cities[i] = 1;
	}
	fastest[start] = 0;
	
	int point;
	while(cities[end] == 1) {
		int flag = 0;
		for(int i = 1; i <= city; i++) {
			if(cities[i] == 0) continue;
			if(flag == 0 && cities[i] == 1) {
				flag += 1;
				point = i;
				continue;
			}
			if(fastest[i] < fastest[point] && cities[i] == 1) {
				point = i;
			}
		}
		cities[point] = 0;
//		printf("point: %d\n",point);
		for(int i = 0; i < bus; i++) {
			if(route[i][0] == point && cities[route[i][1]] == 1) {
				fastest[route[i][1]] = min(fastest[route[i][1]],(fastest[point] + route[i][2]));
			}
		}
	}
	
	return fastest[end];
}

int main(void) {
	
	scanf("%d",&city);
	scanf("%d",&bus);
	for(int i = 0; i < bus; i++) {
		scanf("%d%d%d",&route[i][0],&route[i][1],&route[i][2]);
	}
	
	scanf("%d%d",&start,&end);
	
	printf("%d\n",dijkstra());
	
//	for(int i = 1; i <= city; i++) {
//		printf("%d ",fastest[i]);
//	}
//	putchar('\n');
	return 0;
}

int min(int a,int b) {
	return a > b ? b : a;
}