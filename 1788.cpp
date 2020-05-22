#include<iostream>
#include<algorithm>
using namespace std;

long long int n;
long long int d[1000001] = {0, 1, };

void f() {
	for(int i = 2; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 1000000000;
	}
}

int main() {
	cin >> n;
	
	if(n == -1) {
		cout << 1 << '\n' << 1 << '\n';
	}
	
	else if(n < -1) {
		n *= -1;
		
		f();
		
		if(n % 2 == 0) {
			cout << -1 << '\n' << d[n];
		}
		
		else {
			cout << 1 << '\n' << d[n];
		}
	}
	
	else {
		f();
		
		if(d[n] > 0) {
			cout << 1 << '\n' << d[n];
		}
		
		else if(d[n] == 0) {
			cout << 0 << '\n' << 0 << '\n';
		}
	}
}
