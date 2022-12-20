#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[100001];

int main(void) {
	int N,S;
	scanf("%d%d",&N,&S);
	
	int left = 0;
	int right = 0;
	int minLength = 100001;
	int sum = 0;
	
	arr[0] = 0;
	while(left <= right && right < N + 1){
		if(sum + arr[right] >= S) {
			if(minLength > right - left + 1) {
				minLength = right - left + 1;
			}
			
			sum -= arr[left];
			left += 1;
		} else if(sum + arr[right] < S) {
			//scanf("%d",&arr[right]);
			sum += arr[right];
			right += 1;
			if(right == N + 1) break;
			scanf("%d",&arr[right]);
		}
	}
	
	if(minLength == 100001) {
		printf("0\n");
	} else {
		printf("%d\n",minLength);
	}
	return 0;
}