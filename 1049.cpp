#include<bits/stdc++.h>
using namespace std;

int n, m;
int a = 1000, b = 1000;

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		int x, y;
			
		cin >> x >> y;
		
		a = min(x, a);
		b = min(y, b);
	}
	
	if(a > (6 * b)) {
		a = 6 * b;
	}
	
	if((n % 6) * b > a) {
		cout << ((n / 6) * a) + a << endl;
	}
	
	else {
		cout << ((n / 6) * a) + ((n % 6) * b) << endl;
	}
}