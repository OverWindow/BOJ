#include <stdio.h>

int main(void){
    int n=0;
    scanf("%d", &n);
    int flagg=0;

    for(int i=1; i<n; i++)
    {
        int sum=0;
        sum+=i;
        int m=i;
        while(m!=0)
        {
            sum+=m%10;
            m/=10;
        }
        if(sum==n)
        {
            printf("%d\n", i);
            flagg+=1;
            break;
        }
    }
    if(flagg==0)
        printf("0");
	return 0;
}