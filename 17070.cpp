#include<bits/stdc++.h>
using namespace std;

int n;
int d[17][17];
int dp[3][17][17];
int dx[] = {1, 0, 1};
int dy[] = {0, 1, 1};

bool chk(int x, int y) {
	if(x >= 1 && y >= 1 && x <= n && y <= n) {
		if(d[x][y] == 0) {
			return true;
		}
	}
	
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> d[i][j];
		}
	}
	
	dp[0][1][2] = 1;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(chk(i, j - 1) && chk(i, j)) {
				dp[0][i][j] += dp[0][i][j - 1] + dp[2][i][j - 1];
			}
			
			if(chk(i - 1, j) && chk(i, j)) {
				dp[1][i][j] += dp[1][i - 1][j] + dp[2][i - 1][j];
			}
			
			if(chk(i - 1, j - 1) && chk(i - 1, j) && chk(i, j - 1) && chk(i, j)) {
				dp[2][i][j] += dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
			}
		}
	}
	
	cout << dp[0][n][n] + dp[1][n][n] + dp[2][n][n] << endl;
}
