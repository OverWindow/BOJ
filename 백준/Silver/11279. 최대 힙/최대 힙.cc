#include <iostream>
#define MAX 100001
using namespace std;

int N;
typedef struct {
	int heap_size;
	int heap[MAX];
}HeapType;

void push(HeapType *h,int item) {
	int cur;
	h->heap_size = h->heap_size + 1;
	cur = h->heap_size;
	while((cur != 1) && item > h->heap[cur/2]) {
		h->heap[cur] = h->heap[cur/2];
		cur /= 2;
	}
	h->heap[cur] = item;
	return;
}

int pop(HeapType *h) {
	int parent,child;
	int smallest,item;
	item = h->heap[1];
	smallest = h->heap[h->heap_size];
	h->heap_size = h->heap_size - 1;
	parent = 1;
	child = 2;
	while(child <= h->heap_size) {
		if(child < h->heap_size && h->heap[child] < h->heap[child+1]) {
			child += 1;
		}
		if(smallest >= h->heap[child]) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = smallest;
	return item;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	HeapType h;
	h.heap_size = 0;
		
	cin >> N;

	for(int i = 0; i < N; i++) {
		int input;
		cin >> input;
		
		if(input == 0 && h.heap_size == 0) {
			cout << 0 << "\n";
		} else if(input == 0) {
			cout << pop(&h) << "\n";
		} else {
			push(&h,input);
		}
	}
	
	return 0;
}