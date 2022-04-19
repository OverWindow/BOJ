#include <stdio.h>

int main(void){
    int a,b,c,temp,arr[3] = {0};

    while(1)
    {
        scanf("%d %d %d",&a,&b,&c);
        if (a<=0 && b<=0 && c<=0)
            return 0;
        
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        
        for(int i = 0; i < 2; i++)
        {
            if(arr[i] > arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }

        if(arr[2]*arr[2] == arr[0]*arr[0] + arr[1]*arr[1])
            printf("right\n");
        else
            printf("wrong\n");
        
    }
}