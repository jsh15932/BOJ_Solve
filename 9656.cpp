#include<bits/stdc++.h>
using namespace std;

int n;
int dp[1001];

int main() {
	cin >> n;
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 1;
	dp[4] = 2;
	
	for(int i = 5; i <= n; i++) {
		if(dp[i - 3] == 1 && dp[i - 1] == 1) {
			dp[i] = 2;
		}
		
		else {
			dp[i] = 1;
		}
	}
	
	if(dp[n] == 2) {
		cout << "SK";
	}
	
	else {
		cout << "CY";
	}
}