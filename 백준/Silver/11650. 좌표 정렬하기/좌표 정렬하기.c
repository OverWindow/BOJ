#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x, y;
}point;

int compare(const void *a, const void *b){
	point p1 = *(point*)a, p2 = *(point*)b;
	if (p1.x < p2.x)
		return -1;
	else if (p1.x>p2.x)
		return 1;
	else
	{
		if (p1.y < p2.y)
			return -1;
		else if (p1.y > p2.y)	//참이면 양의 값을 가짐 고로 return 1; 
			return 1;		
		return 0;
	}
}

int main(void){
	int t;
	scanf("%d",&t);
	point p[t];
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d",&p[i].x,&p[i].y);
	}
	qsort(p,t,sizeof(point),compare);
	for (int i = 0; i< t; i++)
	{
		printf("%d %d\n",p[i].x,p[i].y);
	}
	
}
