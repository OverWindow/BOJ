#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N,M;
int start,dest;
struct city{
	int weight;
	int from;
};

vector<struct city> fastest(1001);
vector<pair<int,int>> route[1001];
vector<int> res;

struct cmp {
	bool operator()(pair<int,int> a, pair<int,int> b) {
		return a.second > b.second;
	}
};

int Dijkstra(void) {

	for(int i = 0; i <= N; i++) {
		fastest[i].weight = INF;
		fastest[i].from = i;
//		fastest[i] = {INF,i};
	}
	fastest[start].weight = 0;

	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
	pq.push({start,0});
//	cout << "hello";
	while(!pq.empty()) {
		int cur = pq.top().first;
		int cur_weight = pq.top().second;
		pq.pop();
		
		if(cur == dest) break;
		
		for(pair<int,int> i : route[cur]) {
			if(fastest[i.first].weight > cur_weight + i.second) {
				fastest[i.first].weight = cur_weight + i.second;
				fastest[i.first].from = cur;
				pq.push({i.first,cur_weight + i.second});
			}
		}
	}
	return fastest[dest].weight;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;
	for(int i = 0; i < M; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		
		route[a].push_back({b,c});
	}
	cin >> start >> dest;

	cout << Dijkstra() << "\n";
	
	int cur = dest;
	res.push_back(cur);
	while(cur != start) {
		int tmp = fastest[cur].from;
		res.push_back(tmp);
		cur = tmp;
	}
	
	cout << res.size() << "\n";
	
	for(int i = res.size() - 1; i >= 0; i--) {
		cout << res[i] << " ";
	}
	cout << "\n";
	
	return 0;
}
