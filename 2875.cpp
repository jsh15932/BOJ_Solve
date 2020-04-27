#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k;

int main() {
	cin >> n >> m >> k;
	
	int ans = 0;
	int total = n + m - k;
	
	while(n > 1 && m > 0 && total > 2) {
		n -= 2;
		m -= 1;
		total -= 3;
		ans++;
	}
	
	cout << ans;
}
