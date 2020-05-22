#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int a, b;

int main() {
	cin >> n >> m;
	
	int tmp = m;
	int res = m;
	
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		
		tmp += (a - b);
		
		if(tmp < 0) {
			cout << 0;
			return 0;
		}
		
		res = max(res, tmp);
	}
	
	cout << res;
}
