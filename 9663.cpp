#include<iostream>
#include<algorithm>
using namespace std;

int n, ans;
bool a[16], b[31], c[31];

void Solve(int x) {
	if(x == n) {
		ans++;
		return;
	}
	
	for(int i = 0; i < n; i++) {
		if(a[i] || b[x + i] || c[x - i + (n - 1)]) {
			continue;
		}
		
		a[i] = true;
		b[x + i] = true;
		c[x - i + (n - 1)] = true;
		
		Solve(x + 1);
		
		a[i] = false;
		b[x + i] = false;
		c[x - i + (n - 1)] = false;
	}
}

int main() {
	cin >> n;
	
	Solve(0);
	
	cout << ans;
}
