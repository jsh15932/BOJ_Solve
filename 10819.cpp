#include<iostream>
#include<algorithm>
using namespace std;

int n;
int d[9];

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> d[i];
	}
	
	int ans = -1;
	
	sort(d, d + n);
	
	while(next_permutation(d, d + n)) {
		int tmp = 0;
		
		for(int i = 0; i < n - 1; i++) {
			tmp += abs(d[i] - d[i + 1]);
		}
		
		ans = max(ans, tmp);
	}
	
	cout << ans << endl;
}
