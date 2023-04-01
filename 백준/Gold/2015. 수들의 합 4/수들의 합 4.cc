#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 2015번 누적합 
// 두 가지의 케이스
// 1. i까지의 누적합이 k인 경우
// 2. i와 j사이의 구간합이 k인 경우 두 가지가 있을 것 
// psum[i] - psum[j] = k  ---> psum[i] - k를 통해 psum[j]를 찾는 방식 
		
int main(void) {
	int N,K;
	scanf("%d %d",&N,&K);
	
	vector<int> psum(N+1,0);
	long long cnt = 0;
	map<int,long long> m;
	
	for(int i = 0; i < N; i++) {
		int tmp;
		scanf("%d",&tmp);
		psum[i+1] = psum[i] + tmp;
		
		if(psum[i+1] == K) cnt += 1;
		
		cnt += m[psum[i+1] - K];
		m[psum[i+1]] += 1;
	}
	
	printf("%lld\n",cnt);
	return 0;	
}