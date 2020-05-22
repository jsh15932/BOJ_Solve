#include<iostream>
#include<cmath>
using namespace std;

int n;
int d[10001] = {0, 1, 2, };
int cnt;

int f(int x) {
	cnt = 0;
	
	for(int i = 1; i <= sqrt(x); i++) {
		if(!(x % i)) {
			cnt++;
		}
	}
	
	return cnt;
}

int main() {
	cin >> n;
	
	for(int i = 3; i <= n; i++) {
		d[i] = d[i - 1] + f(i);
	}
	
	cout << d[n];
}
