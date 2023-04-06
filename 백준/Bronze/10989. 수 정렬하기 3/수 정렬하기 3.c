#include <stdio.h>

int main(void){
    
	int t,arr[10001] = {0};
	scanf("%d",&t);
	
	for (int tmp, i =0; i < t; i++)
	{
		scanf("%d",&tmp);
		arr[tmp] += 1;
	}
	
	int count = 1;
	do
	{
		if (arr[count] > 0)
		{
			for (int i = 0; i < arr[count]; i++)
			{
				printf("%d\n",count);
				t -= 1;
			}
		}
		count +=1;
	}while(t > 0);
	return 0;
}