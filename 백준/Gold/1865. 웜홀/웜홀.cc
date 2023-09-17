#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

int T,N,M,W;
struct road {
	int from;
	int to;
	int cost;
};
vector<long long> fastest;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;
	
	while(T--) {
		cin >> N >> M >> W;
		vector<struct road> route;
		
		for(int i = 0; i < M; i++) {
			int a,b,c;
			cin >> a >> b >> c;
			
			route.push_back({a,b,c});
			route.push_back({b,a,c});
		}
		
		for(int i = 0; i < W; i++) {
			int a,b,c;
			cin >> a >> b >> c;
			c *= -1;
			route.push_back({a,b,c});
		}
		
		bool negative_cycle = false;
		for(int i = 1; i <= 1; i++) {
			fastest.resize(N+1,INF);
			fastest[i] = 0;
			
			for(int j = 0; j < N - 1; j++) {
				for(struct road k : route) {
					if(fastest[k.to] > fastest[k.from] + k.cost) {
						fastest[k.to] = fastest[k.from] + k.cost;
					}
				}
			}
			
			for(struct road k : route) {
				if(fastest[k.to] > fastest[k.from] + k.cost) {
					negative_cycle = true;
					break;
				}
			}
			
			if(negative_cycle) {
				break;
			}
		}
		if(negative_cycle) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}