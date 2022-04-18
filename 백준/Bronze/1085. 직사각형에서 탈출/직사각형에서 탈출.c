#include <stdio.h>
#include <stdlib.h>


void bubble_sort(int arr[], int count)
{
	int temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if(arr[j] >= arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(void){
	int x,y,w,h,arr[4] = {0};
	scanf("%d %d %d %d",&x,&y,&w,&h);
	
	int width, height;
	width = w-x;
	height = h-y;
	
	arr[0] = x;
	arr[1] = y;
	arr[2] = width;
	arr[3] = height;
	
	bubble_sort(arr,sizeof(arr)/sizeof(int));
	printf("%d\n",arr[0]);
	
	return 0;
}
