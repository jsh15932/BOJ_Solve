#include<bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int arr[501][501];
int dp[501][501];

int solve(int x, int y) {
	if(dp[x][y] != -1) {
		return dp[x][y];
	}
	
	if(x == 0 && y == 0) {
		return 1;
	}
	
	dp[x][y] = 0;
	
	for(int i = 0; i < 4; i++) {
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < m) {
			if(arr[x][y] < arr[x + dx[i]][y + dy[i]]) {
				dp[x][y] += solve(x + dx[i], y + dy[i]);
			}	
		}
	}
	
	return dp[x][y];
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
			
			dp[i][j] = -1;
		}
	}
	
	cout << solve(n - 1, m - 1);
}
