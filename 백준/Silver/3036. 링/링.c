#include <stdio.h>

int gcd(int a,int b){
	if (a%b ==0)
	{
		return b;
	}
	else
	{
		return gcd(b,a%b);
	}
}

int main(void){

	int n;
	scanf("%d",&n);
	int arr[n];
	for ( int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d",&tmp);
		arr[i] = tmp;
	}

	for( int i = 1; i<n; i++)
	{
		int gcdN;
		gcdN = gcd(arr[0],arr[i]);
		printf("%d/%d\n",arr[0]/gcdN,arr[i]/gcdN);
	}
	return 0;
}