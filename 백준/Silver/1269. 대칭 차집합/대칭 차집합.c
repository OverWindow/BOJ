#include <stdio.h>
#include <stdlib.h>

int compare(const void* first, const void* second) {
	int num1 = *(int*)first;
	int num2 = *(int*)second;
	
	if(num1 > num2) {
		return 1;
	} else if (num1 < num2) {
		return -1;
	} else {
		return 0;
	}
}

int main(void)
{
	int a,b;
	int a_leftover = 0, b_leftover = 0;
	int* a_list = NULL;
	int* b_list = NULL;
	a_list = (int*)malloc(200000 * sizeof(int));
	b_list = (int*)malloc(200000 * sizeof(int));
		
	scanf("%d %d",&a,&b);
	
	for(int i = 0; i < a; i++) {
		scanf("%d",&a_list[i]);
	}
	
	for(int i = 0; i < b; i++) {
		scanf("%d",&b_list[i]);
	}
	
	qsort(a_list,a,sizeof(int),compare);
	qsort(b_list,b,sizeof(int),compare);
	
	for(int i = 0; i < a; i++) {
		int left, right, mid;
		left = 0;
		right = b - 1;
		
		while(left <= right) {
			mid = (left+right)/2;
			
			if(b_list[mid] == a_list[i]) {
				goto endofa;
			} else if (b_list[mid] > a_list[i]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		a_leftover += 1;
		endofa: ;
	}
	
	for(int i = 0; i < b; i++) {
		int left,right,mid;
		left = 0;
		right = a - 1;
		
		while(left <= right) {
			mid = (left+right)/2;
			
			if(a_list[mid] == b_list[i]) {
				goto endofb;
			} else if (a_list[mid] > b_list[i]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		b_leftover += 1;
		endofb: ;
	}
	
	printf("%d\n",a_leftover + b_leftover);

	free(a_list);
	free(b_list);
	return 0;
}