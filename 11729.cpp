#include<bits/stdc++.h>
using namespace std;

void f(int n, int from, int to, int via) {
	if(n == 1) {
		printf("%d %d\n", from, to);
	}
	
	else {
		f(n - 1, from, via, to);
		printf("%d %d\n", from, to);
		f(n - 1, via, to, from);
	}
}

int main() {
	int n;
	
	cin >> n;
	
	cout << (1 << n) - 1 << endl;
	
	f(n, 1, 3, 2);
}