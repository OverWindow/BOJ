#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[1001];
}name;

int compare(const void* first,const void* second) {
	name* a = (name*)first;
	name* b = (name*)second;
	
	if(strcmp(a->name,b->name) > 0) {
		return 1;
	} else if (strcmp(a->name,b->name) < 0) {
		return -1;
	} else if (strcmp(a->name,b->name) == 0) {
		return 0;
	}
}

int main(void)
{
	int size,elaborated_size = 0;
	char word[1001];
	int num = 0;
	scanf("%s",word);
	size = strlen(word);
	
	name* list = NULL;
	list = (name*)malloc(500501 * sizeof(name));
	
	elaborated_size = (size)*(size+1)/2;
	
	for(int i = 1; i <= size; i++) {
		for(int j = 1; j <= size +1 -i; j++) {
			if(i == 1) {
				strncpy(list[num].name,word+j-1,1);
				num += 1;
			} else {
				strncpy(list[num].name,word+j-1,i);
				num += 1;
			}
		}
	}
	
	qsort(list,elaborated_size,sizeof(name),compare);
	
	int result = 0;
	char previous[1001],current[1001];
	for(int i = 0; i < elaborated_size; i++) {
		if (i== 0) {
			result += 1;
			strcpy(previous,list[0].name);
			continue;
		} 
		strcpy(current,list[i].name);
		if(strcmp(current,previous) == 0) {
			;
		} else {
			result += 1;
			strcpy(previous,list[i].name);
		}
	}
	
	printf("%d\n",result);
	
	free(list);
	return 0;
}