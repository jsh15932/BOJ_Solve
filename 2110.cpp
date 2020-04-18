#include<iostream>
#include<algorithm>
using namespace std;

int n, c;

int main() {
	cin >> n >> c;
	
	long long int d[n];
	
	for(int i = 0; i < n; i++) {
		scanf("%lld", &d[i]);
	}
	
	sort(d, d + n);
	
	int left = 1;
	long long int right = d[n - 1] - d[0];
	int result = 0;
	
	while(left <= right) {
		long long int mid = (left + right) / 2;
		int cnt = 1;
		int start = d[0];
		
		for(int i = 1; i < n; i++) {
			if(d[i] - start >= mid) {
				cnt++;
				start = d[i];
			}
		}
		
		if(cnt >= c) {
			result = mid;
			left = mid + 1;
		}
		
		else {
			right = mid - 1;
		}
	}
	
	cout << result;
}
