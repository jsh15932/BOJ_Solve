#include<bits/stdc++.h>
using namespace std;

int e, s, m;

int main() {
	cin >> e >> s >> m;
	
	int x = 1, y = 1, z = 1, ans = 1;
	
	while(1) {
		if(x == e && y == s && z == m) {
			cout << ans << endl;
			
			break;
		}
		
		x++;
		y++;
		z++;
		
		if(x == 16) {
			x = 1;
		}
		
		if(y == 29) {
			y = 1;
		}
		
		if(z == 20) {
			z = 1;
		}
		
		ans++;
	}
}