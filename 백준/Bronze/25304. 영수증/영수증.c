#include <stdio.h>

int main(void)
{
	int totalMoney;
	scanf("%d",&totalMoney);
	
	int totalCount;
	scanf("%d",&totalCount);
	
	int total = 0;
	for(int i = 0; i < totalCount; i++) {
		int money,count;
		scanf("%d %d",&money,&count);
		total += money * count;
	}
	
	if(total == totalMoney) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	
	return 0;
}	