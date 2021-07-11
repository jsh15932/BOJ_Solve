#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	int idx = 1;
	int ans = 0;
	
	while(idx <= n) {
		ans += (n - idx + 1);
		idx *= 10;
	}
	
	cout << ans << endl;
}