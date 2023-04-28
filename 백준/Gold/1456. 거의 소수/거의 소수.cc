#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long min,max;
	cin >> min >> max;
	vector<bool> A(10000001,true);
	
	A[0] = false;
	A[1] = false;
	for(int i = 2; i*i <= 10000001; i++) {
		for(int j = i+i; j <= 10000001; j += i) {
			A[j] = false;
		}
	}
	
	int count = 0;
	for(int i = 2; i <= 10000001; i++) {
		if(A[i] == false) continue;
		
		double temp = i;
		while(i <= (double)max / temp) {
			if(i >= (double)min / temp) {
				count += 1;
			}
			temp = temp * i;
		}
	}
	cout << count << "\n";
	return 0;
}