#include <stdio.h>

//Quick Sort
//Divide And Conquer 형식 
void swap(int* a,int *b ) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition (int arr[],int low,int high) {
	int pivot = arr[high];
	int i = (low-1);
	
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] > pivot) { //오름차순 내림차순 결정 
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}

void quickSort(int arr[],int low,int high) {
	if(low < high) {
		int pi = partition(arr,low,high);
		
		quickSort(arr,low,pi - 1);
		quickSort(arr,pi + 1,high);
	}
}


int main(void)
{
	int participants;
	int cutLine;
	scanf("%d %d",&participants,&cutLine);
	
	int participantsList[participants];
	for(int i = 0 ; i < participants; i++) {
		scanf("%d",&participantsList[i]);
	}
	
	quickSort(participantsList,0,participants - 1);
	
	printf("%d\n",participantsList[cutLine - 1]);
	
	return 0;
}	