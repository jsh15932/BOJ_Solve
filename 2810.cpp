#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s;
int ans = 1;
int cnt, k;

int main() {
	cin >> k >> s;
	
	for(int i = 0; i < k; i++) {
		if(s[i] == 'L') {
			if(cnt % 2 == 1) {
				cnt++;
				continue;
			}
			
			else {
				cnt++;
				ans += 1;
			}
		}
	
		else if(s[i] == 'S') {
			ans += 1;
		}
	}
	
	if(ans > k) {
		ans = k;
	}
	
	cout << ans;
}
