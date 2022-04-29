#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char x[51];
	int y;
}word;

int compare(const void *a, const void *b){
	word p1 = *(word*)a, p2 = *(word*)b;
	if (p1.y < p2.y)
		return -1;
	else if (p1.y>p2.y)
		return 1;
	else
	{	
		for (int i = 0; i <= 51; i++)
		{
			if(p1.x[i] < p2.x[i])
			{
				return -1;
			}
			else if(p1.x[i] > p2.x[i])
			{
				return 1;
			}
		}
		return 0;
	}		
}

int main(void){
	int t;
	scanf("%d\n",&t);
	
	word arr[t];
	for (int i = 0; i < t; i++)
	{
		char tmp;
		int count = 0;
		for(int k = 0; k <= 51; k++)
		{
			arr[i].x[k] = '0';
		}
		while(1)
		{
			scanf("%c",&tmp);
			if (tmp == '\n')
				break;
			arr[i].x[count] = tmp;
			count += 1;
		}
		arr[i].y = count;
	}
	
	qsort(arr,t,sizeof(word),compare);
	
	char before[51] = {'0'};
	
	for (int i = 0; i< t; i++)
	{
		int result = 0;
		for (int j = 0; j <= 51; j++)
		{
			if (before[j] == arr[i].x[j])
				continue;
			else
				result += 1;
		}
		
		if(result == 0)
		{
			continue;
		}
		for (int j = 0; j<=51; j++)
		{
			if (arr[i].x[j] == '0')
			{
				printf("\n");
				break;
			}
			printf("%c",arr[i].x[j]);
		}
		for (int j = 0; j <= 51; j++)
		{
			before[j] = arr[i].x[j];
		}
		
	}	
}
