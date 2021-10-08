#include<bits/stdc++.h>
using namespace std;

int n, sum;

int main() {
	cin >> n;
	
	int arr[n];
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	cin >> sum;
	
	int maxN = 0;
	int tmp = sum;
	
	for(int i = 0; i < n; i++) {
		tmp -= arr[i];
		
		if(arr[i] > maxN) {
			maxN = arr[i];
		}
	}
	
	if(tmp >= 0) {
		cout << maxN << endl;
		
		return 0;
	}
	
	int left = sum / n, right = maxN;
	
	while(left <= right) {
		int mid = (left + right) / 2;
		tmp = sum;
		
		for(int i = 0; i < n; i++) {
			if(mid >= arr[i]) {
				tmp -= arr[i];
			}
			
			else {
				tmp -= mid;
			}
		}
		
		if(tmp >= 0) {
			left = mid + 1;
		}
		
		else {
			right = mid - 1;
		}
	}
	
	cout << right << endl;
}