#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001
using namespace std;

int N,K;
vector<int> fastest;
int di[2] = {-1,1};

struct cmp {
	bool operator()(pair<int,int> a, pair<int,int> b) {
		return a.second > b.second;
	}
};
int Dijkstra(void) {
	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
	fastest.resize(MAX,MAX);
	fastest[N] = 0;
	pq.push({N,0});

	while(!pq.empty()) {
		int cur = pq.top().first;
		int cur_weight = pq.top().second;
		pq.pop();
		
		if(cur == K) break;
		
		for(int i = 0; i < 2; i++) {
			int ncur = cur + di[i];
			if(ncur < 0 || ncur >= MAX) continue;
			
			if(cur_weight + 1 < fastest[ncur]) {
				fastest[ncur] = cur_weight + 1;
				pq.push({ncur,cur_weight + 1});
			}
		}
		
		int ncur = cur * 2;
		if(ncur >= MAX) continue;
		if(cur_weight < fastest[ncur]) {
			fastest[ncur] = cur_weight ;
			pq.push({ncur,cur_weight});
		}
	}
	return fastest[K];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;
	
	cout << Dijkstra() << "\n";
	
	return 0;
}
