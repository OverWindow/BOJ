#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> sum;
vector<long long> remain;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int C;
	cin >> C;
	
	for(int j = 0; j < C; j++) {
		int D,N;
		cin >> D >> N;
		
		sum.clear();
		remain.clear();
		sum.resize(N+1);
		remain.resize(D);
		
		remain[0] += 1;	
		for(int i = 1; i < N+1; i++) {
			int tmp;
			cin >> tmp;
			sum[i] = sum[i-1] + tmp;
			remain[sum[i] % D]++;
		}
		
		long long result = 0;
		for(int i = 0; i < D; i++) {
			result += (remain[i]*(remain[i] - 1))/(2*1);
		}
		cout << result << endl;
	}
	return 0;
}