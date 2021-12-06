#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1001], d[1001];

int main() {
	cin >> n;
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for(int i = 0; i < n; i++) {
		d[i] = 1;
		
		for(int j = 0; j < i; j++) {
			if(arr[i] < arr[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}	
		}
		
		if(d[i] > ans) {
			ans = d[i];
		}
	}
	
	cout << ans;
}