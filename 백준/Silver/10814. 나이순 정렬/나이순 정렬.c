#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x,num;
	char y[101];
}id;

int compare(const void *a, const void *b){
	id num1 = *(id *)a;
	id num2 = *(id *)b;
	
	if(num1.x < num2.x)
		return -1;
	else if (num1.x > num2.x)
		return 1;
	else
	{
		if(num1.num < num2.num)
			return -1;
		else
			return 1;
	}	
	return 0;
}

int main(void){
	int n;
	scanf("%d",&n);
		
	id arr[n];
	for(int i =0;i<n;i++)
	{
		scanf("%d %s",&arr[i].x,&arr[i].y);
		arr[i].num = i;
	}
		
	qsort(arr,n,sizeof(id),compare);
	
	for(int i =0; i<n; i++)
	{
		printf("%d %s\n",arr[i].x,arr[i].y);
	}
	return 0;
}
