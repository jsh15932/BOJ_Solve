#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int k = 1;
	
	cin >> n;
	
	pair<int, int> arr[n];
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(arr[i].first < arr[j].first && arr[i].second < arr[j].second) {
				k++;
			}
		}
		
		cout << k << ' ';
		k = 1;
	}
}