#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 987654321
using namespace std;

int N,E;
int v1,v2;
vector<pair<int,int>> route[801];
vector<int> fastest;

struct cmp {
	bool operator()(pair<int,int> a, pair<int,int> b) {
		return a.second > b.second;
	}
};

void Dijkstra(int start) {
	for(int i = 0; i <= N; i++) {
		fastest[i] = MAX;
	}
	fastest[start] = 0;
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
	pq.push({start,0});
	while(!pq.empty()) {
		int cur = pq.top().first;
		int cur_weight = pq.top().second;
		pq.pop();
		
		for(pair<int,int> i : route[cur]) {
			if(fastest[i.first] > cur_weight + i.second) {
				fastest[i.first] = cur_weight + i.second;
				pq.push({i.first,cur_weight + i.second});
			}
		}
	}

	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> E;
	fastest.resize(N+1,MAX);
	
	for(int i = 0; i < E; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		route[a].push_back({b,c});
		route[b].push_back({a,c});
	}
	
	cin >> v1 >> v2;
	Dijkstra(1);
	int one_to_v1 = fastest[v1];
	int one_to_v2 = fastest[v2];
	
	Dijkstra(v1);
	int v1_to_v2 = fastest[v2];
	int v1_to_end = fastest[N];
	
	Dijkstra(v2);
	int v2_to_end = fastest[N];
	
	int res = MAX;
	res = min(res,one_to_v1 + v1_to_v2 + v2_to_end);
	res = min(res,one_to_v2 + v1_to_v2 + v1_to_end);
	if(v1_to_v2 == MAX || res >= MAX) cout << "-1\n";
	else cout << res << "\n";
	
	return 0;
}