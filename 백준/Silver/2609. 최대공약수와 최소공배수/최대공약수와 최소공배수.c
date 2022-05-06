#include <stdio.h>

int main(void){
	
	int num1, num2, gcf, lcm, mul;
	scanf("%d %d",&num1, &num2);
	mul = num1 * num2;
	
	while(1)
	{
		int tmp;
		tmp = num2;
		num2 = num1 % num2;
		num1 = tmp;
		
		if ( num2 == 0)
			break;
	}
	
	gcf = num1;
	lcm = mul/gcf;
	
	printf("%d\n%d",gcf,lcm);
	return 0;
}
