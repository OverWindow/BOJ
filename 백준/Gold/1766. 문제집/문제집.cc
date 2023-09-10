#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX 32001
using namespace std;

int N,M;
int point[MAX];
vector<int> train[MAX];


struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	priority_queue<int,vector<int>,cmp> pq;
	
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int a,b;
		cin >> a >> b;
		
		train[a].push_back(b);
		point[b] += 1;
	}
	
	for(int i = 1; i <=	N; i++) {
		if(point[i] == 0) {
			pq.push(i);
		}
	}
	
	while(!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		cout << cur << " ";
		
		for(int i : train[cur]) {
			point[i] = max(0,point[i] - 1);
			if(point[i] == 0) {
				pq.push(i);
			}
		}
	}
	return 0;
}
