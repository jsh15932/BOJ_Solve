#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	long long int d[n];
	
	for(int i = 0; i < n; i++) {
		cin >> d[i];
	}
	
	sort(d, d + n);
	
	int cnt = 1;
	int ans_cnt = 1;
	long long int ans = d[0];
	
	for(int i = 1; i < n; i++) {
		if(d[i] == d[i - 1]) {
			cnt += 1;
		}
		else {
			cnt = 1;
		}
		
		if(cnt > ans_cnt) {
			ans_cnt = cnt;
			ans = d[i];
		}
	}
	
	cout << ans;
}
