#include<bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n, m;
int arr[501][501];
int dp[501][501];

int solve(int x, int y) {
	if(x == 0 && y == 0) {
		return 1;
	}
	
	int &res = dp[x][y];
	
	if(res != -1) {
		return res;
	}
	
	res = 0;
	
	for(int i = 0; i < 4; i++) {
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < m) {
			if(arr[x][y] < arr[x + dx[i]][y + dy[i]]) {
				res += solve(x + dx[i], y + dy[i]);
			}
		}
	}
	
	return res;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	cout << solve(n - 1, m - 1);
}