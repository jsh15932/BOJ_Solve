#include<bits/stdc++.h>
using namespace std;

int n;
int arr[11];

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		int k;
		
		cin >> k;
		
		for(int j = 0; j < n; j++) {
			if(k == 0 && arr[j] == 0) {
				arr[j] = i + 1;
				
				break;
			}
			
			else if(arr[j] == 0) {
				k--;
			}
		}
	}
	
	for(int i = 0; i< n; i++) {
		cout << arr[i] << " ";
	}
}