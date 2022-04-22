#include <stdio.h>

int main(void){
    int n,min = -1;
    
    scanf("%d",&n);
    
    for (int every = 1; every <= n; every+=1)
    {
	    int j=1,copy_every,sum = every,arr[8] = {0};
	    copy_every = every;
	    for (int i = 1000000; i >=1; i = i / 10)
	    {
	    	arr[j] = every / i;
	    	//printf("%d_",arr[j]);
	    	every -= (every / i) * i;
	    	j += 1;
		}
		
		
		for (int k = 1; k <= 7; k++)
			sum += arr[k];
			
		if (sum == n)
		{
			if (min < 0)
				min = copy_every;
			else if (copy_every < min)
				min = copy_every;
		}
		
		every = copy_every;
	}
	
	if (min < 0)
		min = 0;
	printf("%d",min);

	return 0;
}