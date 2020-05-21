#include<iostream>
#include<algorithm>
using namespace std;

int d[4];
int a, b;
int res = 0;
int ans = 0;

int main() {
	for(int i = 0; i < 4; i++) {
		cin >> a >> b;
		
		res -= a;
		res += b;
		
		ans = max(ans, res);
	}
	
	cout << ans;
}
