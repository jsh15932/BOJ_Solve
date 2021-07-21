#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	cin >> n;
	
	long long int arr[n];
	long long int arr1[n];
	long long int arr2[n];
	
	for(int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	
	arr1[0] = 1;
	arr2[0] = 1;
	
	for(int i = 1; i < n; i++) {
		arr1[i] = 1;
		
		if(arr[i] >= arr[i - 1]) {
			arr1[i] = arr1[i - 1] + 1;
		}
		
		arr2[i] = 1;
		
		if(arr[i] <= arr[i - 1]) {
			arr2[i] = arr2[i - 1] + 1;
		}
	}
	
	long long int ans = 0;
	
	for(int i = 0; i < n; i++) {
		ans = max(ans, arr1[i]);
		ans = max(ans, arr2[i]);
	}
	
	printf("%lld", ans);
}