#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int N,M;
struct node {
	int from;
	int to;
	int time;
};
vector<struct node> route;
vector<long long> fastest;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		route.push_back({a,b,c});
	}
	
	fastest.resize(N+1,INF);
	fastest[1] = 0;
	
	for(int _ = 0; _ < N-1; _++) {
		for(struct node i : route) {
			if(fastest[i.from] != INF && fastest[i.to] > fastest[i.from] + i.time) {
				fastest[i.to] = fastest[i.from] + i.time;
			}
		}
	}
	
	bool negative_cycle = false;
	
	for(struct node i : route) {
		if(fastest[i.from] != INF && fastest[i.to] > fastest[i.from] + i.time) {
			negative_cycle = true;
		}
	}
	
	if(negative_cycle) {
		cout << -1 << "\n";
	} else {
		for(int i = 2; i <= N; i++) {
			if(fastest[i] == INF) {
				cout << -1 << "\n";
			} else {
				cout << fastest[i] << "\n";
			}
		}
	}
	return 0;
}