#include <stdio.h>

int main(void){
    
    int n,count = 0,num = 1;
    scanf("%d",&n);
    
    while(count < n)
    {
		int num6 = 0,num_before = -1;
		int num_copy = num;
		
		while(num_copy != 0)
		{
			if(num_copy%10 == 6 && num_before == 6 && num6 == 2)
			{
				count += 1;
				break;
			}
			else if(num_copy%10 == 6 && num_before == 6)
				num6 = 2;
			else if(num_copy%10 != 6 && num_before == 6)
				num6 = 0;
				
			num_before = num_copy%10;
			num_copy/=10;
		}
		
    	num += 1;
	}
	
	printf("%d",num-1);
	return 0;
}