#include <stdio.h>
#include <math.h>

int main(void){

    int t,x1,y1,r1,x2,y2,r2;
    double between;
    scanf("%d",&t);

    for(int i = 0; i<t; i++)
    {
        scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);

        between = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
		
		if( r1 + r2 <between)
			printf("0\n");
		else if( fabs(r1-r2) > between)
			printf("0\n");
		else if(between == 0 && r1 == r2)
			printf("-1\n");
		else if(between == r1 + r2)
			printf("1\n");
		else if(between == fabs(r1-r2))
			printf("1\n");
		else
			printf("2\n");	    
    }
    return 0;
}