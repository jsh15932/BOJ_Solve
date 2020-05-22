#include<iostream>
#include<algorithm>
using namespace std;

int n, t;
int ans;
int k, p;

int main() {
	cin >> n >> t;
	
	while(n--) {
		cin >> p;
		k += p;
		
		if(k <= t) {
			ans++;
		}
	}
	
	cout << ans;
}
