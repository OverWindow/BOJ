#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int a,b;
vector<bool> A;

bool TwoPointer(int end, int target) {
	int i = 3;
	int j;
	while(1) {
		if(A[end]) {
			j = end;
			break;
		}
		end--;
	}
	while(i <= j) {
		int sum = i + j;
		
		if(sum == target) {
			a = i;
			b = j;
			return true;
		} else if(sum < target) {
			while(1) {
				if(A[i += 1]) break;
			}
		} else if(sum > target) {
			while(1) {
				if(A[j -= 1]) break;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	A.resize(1000001,true);
	for(int i = 2; i <= 1000000; i++) {
		for(int j = i + i; j <= 1000000; j += i) {
			A[j] = false;
		}
	}
	
	while(1) {
		int input;
		cin >> input;
		if(input == 0) break;
		
		if(TwoPointer(input,input)) {
			cout << input << " = " << a << " + " << b << "\n"; 	
		} else {
			cout << "Goldbach's conjecture is wrong." << "\n";
		}	
	}
	return 0;
}