#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k;

int main() {
	m = 10;
	
	cin >> n;
	
	while(n > m) {
		k = n % m;
		n -= k;
		
		if(k >= 5 * (m / 10)) {
			n += m;
		}
		
		m *= 10;
	}
	
	cout << n;
}
