#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX(a,b) a<b?b:a
#define MIN(a,b) a<b?a:b
#define sz 20
//14889
int score[sz][sz];
int visited[sz];
int N,half;
int team1[sz];
int team2[sz];
int s_min = 9999999;

void start_link() {
	// team1과 team2는 다 들어가있음
	// 각 팀의 능력치를 비교하면 됨
	int team1_score = 0;
	int team2_score = 0;

	for (int i = 0; i < half; i++) {
		for (int k = 1; k <= N; k++) {
			if (team1[i] != k && visited[k]) {
				team1_score += score[team1[i]-1][k-1];
			}
			if (team2[i] != k && !visited[k]) {
				team2_score += score[team2[i]-1][k-1];
			}
		}
	}
	s_min = MIN(s_min, abs(team1_score - team2_score));
}

void func(int x, int start) {
	if (x == half) {
		int j = 0;
		for (int i = 1; i <= N; i++) {
			if (visited[i]) continue;
			team2[j++] = i;
		}
		start_link();
		return;
	}

	for (int i = start; i <= N; i++) {
		if (!visited[i]) {
			team1[x] = i;
			visited[i] = 1;
			func(x + 1, i+1);
			visited[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &N);
	half = N / 2;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &score[i][j]);

	func(0, 1);
	printf("%d\n", s_min);
	return 0;
}