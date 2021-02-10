#include<bits/stdc++.h>
using namespace std;

int x;

int main() {
	cin >> x;
	
	int d[x];
	
	d[0] = 0;
	d[1] = 0;
	
	for(int i = 2; i <= x; i++) {
		d[i] = d[i - 1] + 1;
		
		if(i % 2 == 0 && d[i / 2] < d[i] - 1) {
			d[i] = d[i / 2] + 1;
		}
		
		if(i % 3 == 0 && d[i / 3] < d[i] - 1) {
			d[i] = d[i / 3] + 1;
		}
	}
	
	cout << d[x] << endl;
}
