#include<bits/stdc++.h>
using namespace std;

int n;

int Solve(int n) {
	int sum = n;
	
	while(n) {
		sum += n % 10;
		n /= 10;
	}
	
	return sum;
}

int main() {
	cin >> n;
	
	for(int i = 1; i < n; i++) {
		int sum = Solve(i);
		
		if(sum == n) {
			cout << i << endl;
			
			return 0;
		}
	}
	
	cout << 0;
}