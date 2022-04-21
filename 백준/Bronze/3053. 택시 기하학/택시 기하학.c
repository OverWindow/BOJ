#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(void)
{
    int r;

    scanf("%d",&r);
    printf("%.6f\n",r * r * M_PI);
    printf("%.6f\n",2.0 * r * r);
    return 0;
}