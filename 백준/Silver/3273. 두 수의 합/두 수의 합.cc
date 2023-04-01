#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	scanf("%d",&n);
	vector<int> sorted(n,0);
	
	for(int i = 0; i < n; i++) {
		scanf("%d",&sorted[i]);
	}
	
	int target;
	scanf("%d",&target);
	
	sort(sorted.begin(), sorted.end()); // O(nlogn)
	
	int i = 0; 
	int j = n - 1;
	int ans = 0;
	while(i < j) {
		if(sorted[i] + sorted[j] == target) {
			ans += 1;
			j--;
		} else if(sorted[i] + sorted[j] < target) {
			i++;
		} else if(sorted[i] + sorted[j] > target) {
			j--;
		}
	} // O(n)
	
	printf("%d\n",ans);
	return 0;
}