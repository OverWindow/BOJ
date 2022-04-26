#include <stdio.h>

int main(void){
    
	int t,minus[4001]= {0},plus[4001] = {0},sum = 0;
	scanf("%d",&t);
	
	for(int tmp, i = 0; i < t; i++)
	{
		scanf("%d",&tmp);
		sum += tmp;
		if (tmp>=0)
			plus[tmp] += 1;
		else
			minus[-tmp] += 1;
	}	
	
	//산술평균
	if (sum >= 0)
		printf("%d\n",(int)((sum/(float)t)+0.5));
	else if ((int)((-sum/(float)t)+0.5) == 0)
		printf("0\n");
	else
		printf("%d\n",-(int)((-sum/(float)t)+0.5));
	
	int mode = 0,mode_flag = 1,mode_num; //최반값  
	int count = 0,mid_flag = 0; //중앙값 
	int min,min_flag = 0, max,max_flag = 0; //범위  
	for(int i = 4000; i > 0; i--)
	{
		count += minus[i];
		if(minus[i] > mode)
		{
			mode = minus[i];
			mode_num = -i;
			mode_flag = 0;
		}
		else if (minus[i] == mode && -i > mode_num && minus[i] != 0 && mode_flag < 1)
		{
			mode_num = -i;
			mode_flag = 1;
		}
		
		if ( count >= (t/2 + 1) && mid_flag < 1)
		{
			printf("%d\n",-i);		//중앙값
			mid_flag = 1;
		}
		
		if (count >= 1 && min_flag < 1)
		{
			min = -i;
			min_flag = 1;
		}
		if (count == t && max_flag < 1)
		{
			max = -i;
			max_flag = 1;
		}
	}
	for(int i = 0; i <= 4000; i++)
	{
		count += plus[i];
		if(plus[i] > mode)
		{
			mode = plus[i];
			mode_num = i;
			mode_flag = 0;
		}
		else if (plus[i] == mode && i > mode_num && plus[i] != 0 && mode_flag < 1)
		{
			mode_num = i;
			mode_flag = 1;
		}
		
		if ( count >= (t/2+1) && mid_flag < 1)
		{
			printf("%d\n",i);		//중앙값
			mid_flag = 1;
		}
		if (count >= 1 && min_flag < 1)
		{
			min = i;
			min_flag = 1;
		}
		if (count == t && max_flag <1)
		{
			max = i;
			max_flag = 1;
		}
	}

	//최빈값 
	printf("%d\n",mode_num);
	
	//범위  
	printf("%d\n",max-min);
	return 0;
}
