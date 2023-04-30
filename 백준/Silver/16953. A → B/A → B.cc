#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long start, target;

long long BFS() {
	queue<pair<int,int>> que;
	que.push({start,0});

	while(!que.empty()) {
		long long temp = que.front().first;
		int curValue = que.front().second;
		que.pop();
		if(temp == target) {
			while(!que.empty()) que.pop();
			return curValue;
		}
		
		if(0 <= 2*temp && 2*temp <= target) {
			que.push({2*temp,curValue+1});
		}
		if(0 <= 10*temp + 1 && 10*temp + 1 <= target) {
			que.push({10*temp + 1,curValue+1});
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> start >> target;
	long long ans = BFS();
	if(ans == -1) cout << -1;
	else cout << ans + 1;
	return 0;
}