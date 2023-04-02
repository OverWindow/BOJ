#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//-7 -4 -3 -2 0 2 1 5 9 12

int main(void) {
	int t;
	scanf("%d",&t);
	
	for(int i = 0; i < t; i++) {
		int N,K;
		scanf("%d%d",&N,&K);
		vector<int> arr(N,0);
		
		for(int j = 0; j < N; j++) {
			scanf("%d",&arr[j]);
		}	
		
		sort(arr.begin(),arr.end());
		
		int start = 0;
		int end = N - 1;
		int least;
		int cnt = 0;
		while(start < end) {
			int near = abs(arr[start] + arr[end] - K);
			if(!cnt) {
				least = near;
				cnt++;
			} else {
				if(least == near) {
					cnt += 1;
				} else if(least > near) {
					least = near;
					cnt = 1;
				}
			}
			
			if(arr[start] + arr[end] >= K) {
				end--;
			} else if(arr[start] + arr[end] < K) {
				start++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}