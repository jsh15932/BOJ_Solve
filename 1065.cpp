#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	cin >> n;
	
	if(n < 100) {
		cout << n << endl;
		
		return 0;
	}
	
	int cnt = 99;
	
	for(int i = 100; i <= n; i++) {
		if(((i % 100) / 10) - (i / 100) == (i % 10) - ((i % 100) / 10)) {
			cnt++;
		}
	}
	
	cout << cnt << endl;
}