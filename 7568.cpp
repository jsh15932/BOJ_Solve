#include<bits/stdc++.h>
using namespace std;

int n;
pair<int, int> arr[51];

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	
	int k = 1;
	
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