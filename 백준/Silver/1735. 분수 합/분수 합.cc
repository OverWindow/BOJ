#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int Atop,Abot;
	int Btop,Bbot;
	cin >> Atop >> Abot;
	cin >> Btop >> Bbot;
	
	int resTop,resBot;
	resTop = Atop*Bbot + Btop*Abot;
	resBot = Abot*Bbot;
	
	int a,b;
	a = resTop;
	b = resBot;
	if(resTop < resBot) swap(a,b);
	
	while(1) {
		int tmp = a;
		a = b;
		b = tmp%b;
		if(b == 0) break;
	}
	resTop /= a;
	resBot /= a;
	
	cout << resTop << " " << resBot << "\n";
	return 0;
}