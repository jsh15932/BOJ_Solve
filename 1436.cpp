#include<iostream>
#include<algorithm>
using namespace std;

int n;
int cnt, ans;
int k;

int main() {
	cin >> n;
	
	while(cnt != n) {
		ans++;
		k = 0;
		
		int tmp = ans;
		
		while(tmp != 0) {
			if(tmp % 1000 == 666) {
				k = 1;
			}
			
			tmp /= 10;
		}
		
		if(k) {
			cnt++;
		}
	}
	
	cout << ans;
}
