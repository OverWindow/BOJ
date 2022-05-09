#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	int num1 = *(int *)a, num2 = *(int *)b;
	
	if (num1 < num2)
		return -1;
	else if ( num1 > num2)
		return 1;
	else 
		return 0;
}

int binary_search(int target, int size, int arr[]){
	int start = 0, end = size -1 , mid;
	if (arr[start] == target || arr[end] == target)
	{
		return 1;
	}
	while ( start <= end)
	{
		mid = (start + end)/2;
		if ( arr[mid] > target)
		{
			end = mid -1;
		}
		else if ( arr[mid] < target)
		{
			start = mid + 1;
		}
		else if (arr[mid] == target)
		{
			return 1;
		}
	}
	return 0;
}

int main(void){
	int n,m;
	scanf("%d",&n);
	int n_arr[n];
	for(int i = 0 ; i < n ; i++)
	{
		int tmp;
		scanf("%d",&tmp);
		n_arr[i] = tmp;
	}
		
	scanf("%d",&m);
	int m_arr[m];
	for (int i = 0; i < m ; i++)
	{
		int tmp;
		scanf("%d",&tmp);
		m_arr[i] = tmp;
	}
	
	qsort(n_arr,n,sizeof(int),compare);
	
	for(int i = 0; i < m; i++)
	{
		printf("%d ",binary_search(m_arr[i],n,n_arr));
	}
	return 0;
}