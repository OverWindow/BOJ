#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<bool> isPrime;
vector<int> A;
queue<int> que;
	
void Setup() {
	isPrime.resize(10001,true);
	isPrime[0] = false;
	isPrime[1] = false;
	
	for(int i = 2; i <= 100; i++) {
		for(int j = 2*i; j <= 10000; j+=i) {
			if(isPrime[j] == true) isPrime[j] = false;
		}
	}
	return;
}

void Replace(int tmp, int ten) {
	int start = 0;
	if(ten == 1000) start = ten;
	
	for(int i = start; i <= 9*ten; i+= 1*ten) {
		int newNum;
		if(ten == 1000) {
			newNum = tmp - (tmp/ten)*ten + i;	
		} else{
			newNum = tmp - ((tmp%(ten*10))/ten) * ten + i;
		}
		//cout << newNum << "\n";
		if(newNum == tmp) continue;
		
		if(isPrime[newNum] && A[newNum] == -1) {
			A[newNum] = A[tmp] + 1;
			//cout << A[newNum] << "\n";
			//cout << newNum << "\n";
			que.push(newNum);
		}
	}
	return;
}

void BFS(int start, int end) {
	que.push(start);
	A[start] = 0;
	
	while(!que.empty()) {
		int tmp = que.front();
		que.pop();
		
		//cout << "tmp: " << tmp << "\n";
		
		if(tmp == end) {
			while(!que.empty()) que.pop();
			//cout << "finished\n";
			break;
		}
		
		Replace(tmp,1000);
		Replace(tmp,100);
		Replace(tmp,10);
		Replace(tmp,1);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	Setup();
	
	int T;
	cin >> T;
	A.resize(10001,0);
	for(int i = 0; i < T; i++) {
		fill(A.begin(),A.end(),-1);
		int start,end;
		cin >> start >> end;
		
		BFS(start,end);
		if(A[end] == -1) cout << "Impossible\n";
		else cout << A[end] << "\n";
	}
	return 0;
}