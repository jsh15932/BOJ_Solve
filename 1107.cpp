#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k;
bool chk[10];

int solve(int a) {
	int cnt = 0;
	
	while(a) {
		if(chk[a % 10]) {
			return -1;
		}
		
		a /= 10;
		cnt++;
	}
	
	return cnt;
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		cin >> k;
		chk[k] = true;
	}
	
	int ans = n - 100;
	
	if(ans < 0) {
		ans = -ans;
	}
	
	if(!chk[0]) {
		ans = ans < n + 1 ? ans : n + 1;
	}
	
	int res;
	
	for(int i = n; i < 999999; i++) {
		res = solve(i);
		
		if(res > 0) {
			res += i - n;
			ans = ans < res ? ans : res;
			break;
		}
	}
	
	for(int i = n; i > 0; i--) {
		res = solve(i);
		
		if(res > 0) {
			res += n - i;
			ans = ans < res ? ans : res;
			break;
		}
	}
	
	cout << ans;
}
