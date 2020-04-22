#include<iostream>
#include<algorithm>
using namespace std;

long long int d[200001];
int n, c;

int main() {
	cin >> n >> c;
	
	for(int i = 0; i < n; i++) {
		scanf("%lld", &d[i]);
	}
	
	sort(d, d + n);
	
	long long int left = 1;
	long long int right = d[n - 1] - d[0];
	long long int result = 0;
	
	while(left <= right) {
		long long int mid = (left + right) / 2;
		long long int start = d[0];
		int cnt = 1;
		
		for(int i = 0; i < n; i++) {
			if(d[i] - start >= mid) {
				start = d[i];
				cnt++;
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
