#include <iostream>
using namespace std;

long prefixSum[100001];
int main(void) {
	int N,M;
	cin >> N >> M;

	prefixSum[0] = 0;
	for(int i = 0; i < N; i++) {
		long tmp;
		scanf("%ld",&tmp);
		prefixSum[i+1] = prefixSum[i] + tmp;
	}
	
	for(int i = 0; i < M; i++) {
		int m,n;
		scanf("%ld%ld",&m,&n);
		printf("%ld\n",prefixSum[n] - prefixSum[m-1]);
	}
	return 0;
}