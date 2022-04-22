#include <stdio.h>

int main(void){
    int n,min = -1;
    
    scanf("%d",&n);
    
    for (int every = 1; every <= n; every+=1)
    {
	    int j=1,copy_every,sum = every,arr[8] = {0};
	    copy_every = every;
	    
	    // 각 자리수로 분류하기 
	    for (int i = 1000000; i >=1; i = i / 10)
	    {
	    	arr[j] = copy_every / i;
	    	copy_every -= (copy_every / i) * i;
	    	j += 1;
		}
		
		//각 자리수 다 더하기 
		for (int k = 1; k <= 7; k++)
			sum += arr[k];
		
		if (sum == n)
		{
			min = every;
			break;
		}
	}
	
	if (min < 0)
		min = 0;
		
	printf("%d",min);

	return 0;
}