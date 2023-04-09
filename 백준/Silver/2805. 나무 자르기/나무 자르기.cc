#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N,height;
long M;
vector<int> tree;

void cut() {
	int i = 0;
	int j = 1000000000;
	
	while(i <= j) {
		long long wood = 0;
		int mid = ( i + j ) / 2;
		for(int k = 0; k < N; k++) {
			if(tree[k] - mid > 0) wood += tree[k] - mid;
		}
		
		if(wood >= M) {
			i = mid + 1;
			height = max(height,mid);
		} else if(wood < M) {
			j = mid - 1;
		}
	}
	return; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	tree.resize(N,0);
	height = 0;
	for(int i = 0; i < N; i++) {
		cin >> tree[i];
	}
	
	cut();
	cout << height << "\n";
	return 0;	
}