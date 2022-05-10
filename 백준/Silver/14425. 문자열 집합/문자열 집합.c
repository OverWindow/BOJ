#include <stdio.h>

int N, M, result = 0, trie[10000 * 505][30], add = 0, endOfWord[10000 * 505];
char word[502];

void insert(char* word) {
	int idx = 0, num, cur = 0;
	while (word[idx] != '\0') {
		num = (int)word[idx] - 'a';
		if (!trie[cur][num]) trie[cur][num] = ++add;
		cur = trie[cur][num]; idx++;
	}
	endOfWord[cur] = 1;
}

int find(char* word) {
	int idx = 0, num, cur = 0;
	while (word[idx] != '\0') {
		num = (int)word[idx] - 'a';
		if (!trie[cur][num]) return 0;
		cur = trie[cur][num]; idx++;
	}
	if (endOfWord[cur]) return 1;
	else return 0;
}

int main(void) {
	scanf("%d %d", &N, &M);
	// N
	for (int n = 0; n < N; n++) {
		scanf("%s", word);
		insert(word);
	}
	// M
	for (int m = 0; m < M; m++) {
		scanf("%s", word);
		if (find(word)) result++;
	}
	printf("%d", result);
}