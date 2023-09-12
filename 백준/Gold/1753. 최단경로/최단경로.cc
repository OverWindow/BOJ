#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 300000
using namespace std;

struct cmp {
	bool operator()(pair<int,int> a,pair<int,int> b) {
		return a.second > b.second;
	}
};

int V,E,K;
vector<pair<int,int>> route[20001];
priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
vector<int> fastest;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> V >> E;
	cin >> K;
	
	fastest.resize(V+1,MAX);

	for(int i = 0; i < E; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		
		route[a].push_back({b,c});
	}
	
	fastest[K] = 0;
	pq.push({K,0});
	while(!pq.empty()) {
		int v = pq.top().first;
		int w = pq.top().second;
		pq.pop();
		
		for(pair<int,int> i : route[v]) {
			if(w + i.second < fastest[i.first]) {
				pq.push({i.first,w+i.second});
				fastest[i.first] = min(fastest[i.first],w + i.second);
			}
		}
	}
	for(int i = 1; i <= V; i++) {
		if(fastest[i] == MAX) cout << "INF\n";
		else cout << fastest[i] << "\n";
	}
	return 0;
}