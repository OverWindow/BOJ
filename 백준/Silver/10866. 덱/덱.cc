#include <iostream>
using namespace std;

typedef struct node {
	int value;
	node *forward;
	node *backward;
}node;

typedef struct {
	int size;
	node *front;
	node *back;
}deque;

int empty(deque *dq) {
	if(dq->size == 0) {
		return 1;
	} else {
		return 0;
	}
}

void push_front(deque *dq,int d) {
	node *tmp = new node;
	tmp->value = d;
	
	if(empty(dq)) {
		dq->front = tmp;
		dq->back = tmp;
	} else {
		dq->front->forward = tmp;
		tmp->backward = dq->front;
		dq->front = tmp;
	}
	dq->size += 1;
	return;
}

void push_back(deque *dq,int d) {
	node *tmp = new node;
	tmp->value = d;
	
	if(empty(dq)) {
		dq->front = tmp;
		dq->back = tmp;
	} else {
		dq->back->backward = tmp;
		tmp->forward = dq->back;
		dq->back = tmp;
	}
	dq->size += 1;
	return;
}

int pop_front(deque *dq) {
	node *tmp;
	
	if(empty(dq)) {
		return -1;
	}
	
	tmp = dq->front;
	int d = tmp->value;
	dq->front = tmp->backward;
	dq->size -= 1;
	delete tmp;
	return d;
}

int pop_back(deque *dq) {
	node *tmp;
	
	if(empty(dq)) {
		return -1;
	}
	
	tmp = dq->back;
	int d = tmp->value;
	dq->back = tmp->forward;
	dq->size -= 1;
	delete tmp;
	return d;
}

int front(deque *dq) {
	if(empty(dq)) {
		return -1;
	} 
	return dq->front->value;
}

int back(deque *dq) {
	if(empty(dq)) {
		return -1;
	}
	return dq->back->value;
}

int main(void) {
	deque dq;
	dq.size = 0;
	
	int N;
	cin >> N;
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if(s == "front") {
			cout << front(&dq) << "\n";
		} else if(s == "back") {
			cout << back(&dq) << "\n";
		} else if(s == "size") {
			cout << dq.size << "\n";
		} else if(s == "empty") {
			cout << empty(&dq) << "\n";
		} else if(s == "pop_front") {
			cout << pop_front(&dq) << "\n";
		} else if(s == "pop_back") {
			cout << pop_back(&dq) << "\n";
		} else {
			int tmp;
			cin >> tmp;
			if(s == "push_front") {
				push_front(&dq,tmp);
			} else if(s == "push_back") {
				push_back(&dq,tmp);
			}
		}
	}
	return 0;
}