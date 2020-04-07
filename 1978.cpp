#include<iostream>
using namespace std;

int main() {
	int n;
	int num[1001];
	int cnt = 0;
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> num[i];
	}
	
	for(int i = 0; i < n; i++) {
		int div = 1;
		
		if(num[i] == 1) {
			cnt++;
			continue;
		}
		
		while(div * div <= num[i]) {
			if(div == 1) {
				div++;
				continue;
			}
			
			if(num[i] % div == 0) {
				cnt++;
				break;
			}
			
			div++;
		}
	}
	
	cout << n - cnt;
}
