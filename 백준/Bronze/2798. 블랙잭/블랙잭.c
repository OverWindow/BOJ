#include <stdio.h>

int main(void){
	int N,M,max = 0;
	scanf("%d %d",&N,&M);
	int arr[100]={0,};
	
	for( int i = 0; i<N; i++)
		scanf("%d",&arr[i]);
	


	for (int i = 0; i < N-2; i++)
	{
		for(int j = i + 1; j<N-1; j++)
		{
			for(int k = j + 1; k<N; k++)
			{
				if ((arr[i]+arr[j]+arr[k] <= M)&&(arr[i]+arr[j]+arr[k] >=max))	
					max = arr[i]+arr[j]+arr[k];
				
			}
		}		
	}
	
	printf("%d",max);
	return 0;
}