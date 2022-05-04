#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	int num1 = *(int *)a, num2 = *(int *)b;
	
	if (num1 < num2)
		return -1;
	else if (num1 > num2)
		return 1;
	else 
		return 0;
}

int unique(int arr[], int size){
	int i, j = 0;
	for (i = 1; i < size; i++)
	{
		if (arr[j] == arr[i])
			continue;
		arr[++j] = arr[i];
	}
	return ++j;
}

int binarysearch(int arr[], int size, int key){
	int left = 0,right = size -1, mid;
	while (left <= right){
		mid = (left + right)/2;
		if (arr[mid] < key)
			left = mid + 1;
		else if( arr[mid] > key)
			right = mid -1;
		else 
			return mid;
	}
}

int main(void){
	int n;
	scanf("%d",&n);
	int arr[n],sorted[n];
	
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d",&tmp);
		arr[i] = tmp;
		sorted[i] = tmp;
	}
	
	qsort(sorted,n,sizeof(int),compare);
	
	int cnt = unique(sorted, n);
	
	for (int i = 0; i < n; i++)
	{
		int tmp = binarysearch(sorted, cnt, arr[i]);
		printf("%d ",tmp);
	}
	return 0;
}
