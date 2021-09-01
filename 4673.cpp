#include<bits/stdc++.h>
using namespace std;

bool chk[10001];

int Solve(int n) {
	int sum = n;
	
	while(true) {
		if(n == 0) {
			break;
		}
		
		sum += n % 10;
		n = n / 10;
	}
	
	return sum;
}

int main() {
	for(int i = 1; i <= 10000; i++) {
		int idx = Solve(i);
		
		if(idx <= 10000) {
			chk[idx] = true;
		}
	}
	
	for(int i = 1; i <= 10000; i++) {
		if(!chk[i]) {
			cout << i << endl;
		}
	}
}