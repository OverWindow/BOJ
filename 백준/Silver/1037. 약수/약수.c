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


int main(void){
	
	int n;
	scanf("%d",&n);
	int arr[n];
	
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d",&tmp);
		arr[i] = tmp;
	}
	
	qsort(arr,n,sizeof(int),compare);
	
	int result;
	result = arr[0] * arr[n-1];
	printf("%d\n",result);
	
	return 0;
}
