#include <stdio.h>
#include <string.h>

int main(void)
{
	int t,k,n;
	scanf("%d",&t);
	

	for (int i = 0; i<t; i++){
		scanf("%d",&k);
		scanf("%d",&n);
		int bf[n];
		int af[n];
		
		for (int i = 0; i<n;i++){
			bf[i] = i+1;
		}
		
		for (int _ = 0; _<k;_++){
			memset(af,0,sizeof(af));
			for (int j = 0; j<n; j++){
				for(int k = 0; k<=j; k++){
					af[j] += bf[k];
				}
			}
			memcpy(bf,af,sizeof(af));
		}
		printf("%d\n",bf[n-1]);	
	}
}