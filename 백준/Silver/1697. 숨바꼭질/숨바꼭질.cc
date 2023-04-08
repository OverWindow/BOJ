#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N,K,least;
vector<int> visited;

void BFS() {
	visited[N] = 1;
	queue<int> que;
	que.push(N);
	
	while(!que.empty()) {
		int cur = que.front();
		que.pop();
		
		if(cur == K) {
			break;
		}	
		
		if(cur <= 100000 / 2) {
			if(!visited[cur * 2]) {
				que.push(cur * 2);
				visited[cur * 2] = visited[cur] + 1;
			}
		}
		if(cur != 0) {
			if(!visited[cur - 1]) {
				que.push(cur - 1);
				visited[cur - 1] = visited[cur] + 1;
			}
		}
		if(cur != 100000) {
			if(!visited[cur + 1]) {
				que.push(cur + 1);
				visited[cur + 1] = visited[cur] + 1;
			}
		}
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;
	visited.resize(100001,0);
	
	BFS();
	
	cout << visited[K] - 1 << "\n";
	return 0;	
}