#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[21];	
}name;

int compare(const void* first,const void* second) {
	name* a = (name*)first;
	name* b = (name*)second;
	
	if(strcmp(a->name,b->name) >0) {
		return 1;
	} else {
		return -1;
	}
}

int main(void)
{
	int n,m,result = 0;
	scanf("%d %d",&n,&m);
	
	name* hear = NULL;
	name* see = NULL;
	name* seeandhear = NULL;
	hear = (name*)malloc(500000 * sizeof(name));
	see = (name*)malloc(500000 * sizeof(name));
	seeandhear = (name*)malloc(500000 * sizeof(name));
	
	for(int i = 0; i < n; i++) {
		scanf(" %s",hear[i].name);
	}
	 
	for(int i = 0; i < m; i++) {
		scanf(" %s",see[i].name);
	}
	
	qsort(hear,n,sizeof(name),compare);
	
	for(int i = 0; i < m; i++) {
		int left, right, mid;
		left = 0;
		right = n-1;
		
		while(left <= right) {
			mid = (left+right)/2;
			
			if(strcmp(hear[mid].name,see[i].name) == 0) {
				strcpy(seeandhear[result].name,see[i].name);
				result += 1;
				goto end;
			} else if (strcmp(hear[mid].name,see[i].name) > 0) {
				right = mid - 1;
			} else {
				left = mid + 1;	
			}
		}
		end: ;
	}
	
	printf("%d\n",result);
	
	qsort(seeandhear,result,sizeof(name),compare);
	for(int i = 0; i < result; i++) {
		printf("%s\n",seeandhear[i].name);
	}
	
	free(seeandhear);
	free(hear);
	free(see);
	return 0;
}