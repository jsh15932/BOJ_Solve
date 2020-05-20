#include<iostream>
#include<algorithm>
using namespace std;
#define INF 1000001

int n;
int ans = -1;

int main() {
	cin >> n;
	
	for(int i = 1; i <= INF; i++) {
		int cur = i;
		int sum = 0;
		
		while(cur != 0) {
			sum += (cur % 10);
			cur /= 10;
		}
		
		if(n == (i + sum)) {
			ans = i;
			break;
		}
	}
	
	if(ans == - 1) {
		cout << 0; 
	}
	
	else {
		cout << ans;
	}
}
