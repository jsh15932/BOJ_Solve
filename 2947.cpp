#include<bits/stdc++.h>
using namespace std;

int arr[5];

int main() {
	for(int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	
	bool chk = true;
	
	while(chk) {
		chk = false;
		
		for(int i = 0; i < 4; i++) {
			if(arr[i] > arr[i + 1]) {
				chk = true;
				swap(arr[i], arr[i + 1]);
				
				for(int i = 0; i < 5; i++) {
					cout << arr[i] << " ";
				}
				
				cout << endl;
			}
		}
	}
}