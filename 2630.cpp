#include<bits/stdc++.h>
using namespace std;

int n;
int arr[129][129];
int a, b;

bool chk(int x, int y, int w) {
	for(int i = x; i < x + w; i++) {
		for(int j = y; j < y + w; j++) {
			if(arr[i][j] != arr[x][y]) {
				return false;
			}
		}
	}
	
	return true;
}

void solve(int x, int y, int n) {
	if(!chk(x, y, n)) {
		solve(x + n / 2, y + n / 2, n / 2);
		solve(x, y + n / 2, n / 2);
		solve(x + n / 2, y, n / 2);
		solve(x, y, n / 2);
	}
	
	else {
		if(arr[x][y] == 0) {
			a++;
		}
		
		else {
			b++;
		}
	}
	
	return;
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	solve(0, 0, n);
	
	cout << a << '\n' << b;
}