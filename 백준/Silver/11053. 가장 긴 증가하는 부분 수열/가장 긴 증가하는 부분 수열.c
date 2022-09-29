#include <stdio.h>

int max(int a, int b);

int main(void){

    int N;

    scanf("%d", &N);

    int A[N];

    for(int i=0; i<N; i++){

        scanf("%d", &A[i]);

    }

    int LIS[N]; //LIS[i]: A[i]를 포함하는 가장 긴 부분 수열의 길이

    LIS[0]=1;  

    for(int i=1; i<N; i++){

        LIS[i]=1;

        for(int j=0; j<i; j++){

            if(A[i]>A[j]){

                LIS[i] = max(LIS[i], LIS[j]+1);

            }

        }

    }

    int max=0;

    for(int i=0; i<N; i++){

        if(LIS[i]>max)

            max=LIS[i];

    }

    printf("%d\n", max);

}

int max(int a, int b){

    if(a>b)

        return a;

    else

        return b;

}