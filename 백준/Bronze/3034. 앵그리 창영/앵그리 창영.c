#include <stdio.h>
#include <math.h>

int main(void){
	
	int n,w,h;
	scanf("%d %d %d",&n,&w,&h);
	
	
	for ( int i = 0 ; i < n; i++)
	{
		int tmp;
		scanf("%d",&tmp);
		if ( tmp <= sqrt(w*w + h*h))
		{
			printf("DA\n");
		}
		else
		{
			printf("NE\n");
		}
	}
	
	return 0;
}
	