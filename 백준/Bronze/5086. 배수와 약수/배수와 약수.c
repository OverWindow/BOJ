#include <stdio.h>


int main(void){
	
	while (1)
	{
		int num1, num2;
		scanf("%d %d",&num1,&num2);
		
		if (num1 == 0 && num2 == 0)
		{
			break;
		}
		else if ( num1 / num2 == (float)num1 / num2)
		{
			printf("multiple\n");
		}
		else if(num2/ num1 == (float)num2/num1 )
		{
			printf("factor\n");
		}
		else
		{
			printf("neither\n");
		}
	}
	return 0;
}

