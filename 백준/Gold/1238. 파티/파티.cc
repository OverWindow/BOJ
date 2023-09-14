#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N,M,X;
vector<pair<int,int>> route[1001];
vector<int> fastest;

struct cmp {
	bool operator()(pair<int,int> a, pair<int,int> b) {
		return a.second > b.second;
	}
};

int Dijkstra(int start, int end) {
	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
	vector<int> fastest;
	fastest.resize(N+1,INF);
	fastest[start] = 0;
	pq.push({start,0});
	
	while(!pq.empty()) {
		int cur = pq.top().first;
		int cur_weight = pq.top().second;
		pq.pop();
		
		if(cur == end) {
			break;
		}
		
		for(pair<int,int> i : route[cur]) {
			if(fastest[i.first] > cur_weight + i.second) {
				fastest[i.first] = cur_weight + i.second;
				pq.push({i.first,cur_weight + i.second});
			}
		}
	}
	return fastest[end];
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> X;
	
	for(int i = 0; i < M; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		
		route[a].push_back({b,c});
	}
	
	int res = 0;
	for(int i = 1; i <= N; i++) {
		res = max(res,Dijkstra(i,X) + Dijkstra(X,i));
	}
	
	cout << res << "\n";
	
	return 0;
}