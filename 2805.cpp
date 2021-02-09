#include<bits/stdc++.h>
using namespace std;

long long int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	long long int d[n];
	long long int INF = 0;
	
	for(int i = 0; i < n; i++) {
		cin >> d[i];
		
		if(d[i] > INF) {
			INF = d[i];
		}
	}
	
	long long int left = 0;
	long long int right = INF;
	long long int res = 0;
	
	while(left <= right) {
		long long int mid = (left + right) / 2;
		long long int total = 0;
		
		for(int i = 0; i < n; i++) {
			if(d[i] > mid) {
				total += d[i] - mid;
			}
		}
		
		if(total >= m) {
			res = mid;
			left = mid + 1;
		}
		
		else {
			right = mid - 1;
		}
	}
	
	cout << res << endl;
}
