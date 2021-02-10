#include<bits/stdc++.h>
using namespace std;

int n, t;

int main() {
	cin >> t;
	
	while(t--) {
		cin >> n;
		
		int d[n];
		
		d[0] = 0;
		d[1] = 1;
		d[2] = 2;
		d[3] = 4;
		
		for(int i = 4; i <= n; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		
		cout << d[n] << endl;
	}
}
