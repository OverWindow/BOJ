#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int T,F;
map<string,pair<string,int>> flist;

string find(string cur) {
	if(cur.compare(flist[cur].first) == 0) {
		return cur;
	}
	flist[cur].first = find(flist[cur].first);
	return flist[cur].first;
}

void uni(string a, string b) {
	a = find(a);
	b = find(b);
	
	if(a > b) swap(a,b);
	if(a == b) return;
	
	flist[b].first = a;
	flist[a].second += flist[b].second;
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;
	for(int _ = 0; _ < T; _++) {
		cin >> F;
		for(int i = 0; i < F; i++) {
			string a,b;
			cin >> a >> b;
			
			if(flist.find(a) == flist.end()) {
				flist[a].first = a;
				flist[a].second = 1;
			}
			if(flist.find(b) == flist.end()) {
				flist[b].first = b;
				flist[b].second = 1;
			}
					
			uni(a,b);
				
			cout << flist[find(a)].second << "\n";
		}
//		for(auto element : flist) {
//			cout << element.first << " " << element.second.first << " " << element.second.second << "\n";
//		}
		flist.clear();
	}
	return 0;
}