#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b)
{
	if(a == 0) 
		return b;
	if(b == 0) 
		return a;
	if(a % b == 0) 
		return b;
	else 
		return gcd(b, a%b);
}


int main(void){
	
	int n,gcdN;
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d",&tmp);
		arr[i] = tmp;
	
		if(i==0)
			continue;
		
		arr[i] = abs(arr[i] - arr[0]);
		
		if(i==1)
		{
			gcdN = arr[1];
			continue;
		}
		gcdN = gcd(gcdN, arr[i]);
		
	}
	
	for ( int i = 2; i <= gcdN/2; i++)
	{
		if ( gcdN % i == 0)
		{
			printf("%d ",i);
		}
	}
	printf("%d",gcdN);
	return 0;	
}