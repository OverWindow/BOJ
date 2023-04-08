#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> paper;
int Aa = 0;
int Ab = 0;
int Ac = 0;

bool check(int a, int b, int N,int target) {
	int tmp = 0;
	for(int i = a; i < a+N; i++) {
		for(int j = b; j < b+N; j++) {
			if(paper[i][j] == target) tmp += 1;
		}
	}
	if(tmp == N*N) return true;
	else return false;
}

void cut(int i, int j, int N) {
	if(check(i,j,N,-1)) {
		Aa += 1;
		return;
	}
	if(check(i,j,N,0)) {
		Ab += 1;
		return;
	}
	if(check(i,j,N,1)) {
		Ac += 1;
		return;
	}	
	for(int k = 0; k < 9; k++) {
		int m = i + (k/3) * (N/3);
		int n = j + (k%3) * (N/3);
		cut(m,n,N/3);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	paper.resize(N,vector<int>(N,0));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}	

	cut(0,0,N);
	cout << Aa << "\n" << Ab << "\n" << Ac << "\n";
	return 0;	
}