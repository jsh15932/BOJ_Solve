#include<iostream>
#include<algorithm>
using namespace std;

int t;
int d[8];

int main() {
	cin >> t;
	
	while(t--) {
		int x = 0;
		int y = 0;
		int a = 0;
		int b = 0;
		
		for(int i = 0; i < 8; i++) {
			cin >> d[i];
		}
		
		x += (d[0] + d[4]);
		y += (d[1] + d[5]);
		a += (d[2] + d[6]);
		b += (d[3] + d[7]);
		
		if((x *= 1) < 1) {
			x = 1;
		}
		
		if((y *= 5) < 1) {
			y = 5;
		}
		
		if((a *= 2) < 0) {
			a = 0;
		}
		
		b *= 2;
		
		cout << x + y + a + b << endl;
	}
}
