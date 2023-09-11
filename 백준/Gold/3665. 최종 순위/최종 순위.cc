#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int T;
vector<int> arrayNum;
vector<int> connect[501];
vector<int> pointed;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;

	for(int _ = 0; _ < T; _++) {
		int N,M;
		cin >> N;
		pointed.resize(501,0);
		fill(pointed.begin(),pointed.end(),0);
		for(int i = 0; i <= N; i++) {
			connect[i].clear();
		}
		arrayNum.clear();
		
		for(int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			arrayNum.push_back(tmp);
			
			if(i == 0) continue;
			
			for(int j : arrayNum) {
				if(j == tmp) continue;
				connect[j].push_back(tmp);
			}
			pointed[tmp] = i;
		}
		
//		for(int i = 1; i <= N; i++) {
//			cout << pointed[i] << " ";
//		}
//		for(int i : array) {
//			cout << i << " ";
//		}
//		for(int i : connect[5]) {
//			cout << i << " ";
//		}

		cin >> M;
		for(int i = 0; i < M; i++) {
			int a,b;
			cin >> a >> b;
			
			int first,second;
			for(int j : arrayNum) {
				if(a == j) {
					first = a;
					second = b;
					break;
				} else if(b == j) {
					first = b;
					second = a;
					break;
				}
			}
			
			pointed[first] += 1;
			pointed[second] = max(0,pointed[second] - 1);
//			cout << first << second << "\n";	
//			for(int j : connect[first]) {
//				cout << j << " ";
//			}		
			connect[first].erase(find(connect[first].begin(),connect[first].end(),second));
			connect[second].push_back(first);
		}
		
		queue<int> que;
		for(int i = 1; i <= N; i++) {
			if(pointed[i] == 0) {
				que.push(i);
			}
		}
		
		if(que.size() >= 2) {
			cout << "?" << "\n";
			continue;
		} else if(que.size() == 0) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		
		bool idk = false;
		vector<int> result;
		while(!que.empty()) {
			int cur = que.front();
			que.pop();
			result.push_back(cur);
			
			for(int i : connect[cur]) {
				pointed[i] = max(0,pointed[i] - 1);
				if(pointed[i] == 0) {
					que.push(i);
				}
			}
			
			if(que.size() >= 2) {
				idk = true;
				break;
			}
		}
		
		if(idk) {
			cout << "?\n";
		} else if(result.size() != N) {
			cout << "IMPOSSIBLE\n";
		} else {
			for(int i : result) {
				cout << i << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}