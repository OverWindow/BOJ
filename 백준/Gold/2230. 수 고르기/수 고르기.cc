	#include <iostream>
	#include <vector>
	#include <algorithm>
	using namespace std;
	
	int main(void) {
		int N,M;
		scanf("%d %d",&N, &M);
		
		vector<int> arr(N,0);
		
		for(int i = 0; i < N; i++) {
			scanf("%d",&arr[i]);
		}
		
		sort(arr.begin(),arr.end());
		
		int i = 0; 
		int j = 0;
		int least = arr[N-1] - arr[0];
		while(i < N && j < N) {
			i = min(i,N);
			j = min(j,N);
			if(arr[j] - arr[i] >= M) {
				least = min(least,arr[j] - arr[i]);
				i++;
			} else if(arr[j] - arr[i] < M) {
				j++;
			}
		}
	
		printf("%d\n",least);
		return 0;
	}