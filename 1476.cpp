#include<iostream>
#include<algorithm>
using namespace std;

int e, s, m;
int ans;

int main() {
	cin >> e >> s >> m;
	
	while(++ans) {
		if(!((ans - e) % 15 || (ans - s) % 28 || (ans - m) % 19)) {
			break;
		}
	}
	
	cout << ans;
}
