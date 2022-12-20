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
	
	for(int i = 0; i < N; i++) {
		scanf("%d",&arr[i]);
	}	

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
		}
	}
	
	if(minLength == 100001) {
		printf("0\n");
	} else {
		printf("%d\n",minLength);
	}
	return 0;
}