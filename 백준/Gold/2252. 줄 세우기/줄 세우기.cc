#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
vector<int> A[32000 + 1];
int indegree[32000 + 1];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		A[a].push_back(b);
		indegree[b] += 1;	
	}
	
	queue<int> que;
	for(int i = 1; i <= N; i++) {
		if(indegree[i] == 0) {
			que.push(i);
		}
	}
	
	while(!que.empty()) {
		int now = que.front();
		que.pop();
		cout << now << " ";
		for(int next : A[now]) {
			indegree[next] = max(0,indegree[next] - 1);
			if(indegree[next] == 0) {
				que.push(next);
			}
		}
	}
	return 0;
}