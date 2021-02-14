#include<bits/stdc++.h>
using namespace std;

struct C {
	int x, y;
};

int r, c, t;
int x = -1;
int y, ans;
int dp[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void solve() {
	while(t--) {
		int d[51][51] = {0, };
		memcpy(d, dp, sizeof(dp));
		
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(dp[i][j] >= 5) {
					int p = dp[i][j] / 5;
					
					for(int k = 0; k < 4; k++) {
						if(i + dx[k] >= 0 && j + dy[k] >= 0 && i + dx[k] < r && j + dy[k] < c) {
							if(dp[i + dx[k]][j + dy[k]] != -1) {
								d[i + dx[k]][j + dy[k]] += p;
								d[i][j] -= p;
							}
						} 
					}
				}
			}
		}
		
		memcpy(dp, d, sizeof(d));
		
		for(int i = x - 2; i >= 0; i--) {
			dp[i + 1][0] = dp[i][0];
		}
		
		for(int i = 0; i < c - 1; i++) {
			dp[0][i] = dp[0][i + 1];
		}
		
		for(int i = 0; i < x; i++) {
			dp[i][c - 1] = dp[i + 1][c - 1];
		}
		
		for(int i = c - 2; i >= 0; i--) {
			dp[x][i + 1] = dp[x][i];
		}
		
		dp[x][1] = 0;
		
		for(int i = y + 1; i < r - 1; i++) {
			dp[i][0] = dp[i + 1][0];
		}
		
		for(int i = 0; i < c - 1; i++) {
			dp[r - 1][i] = dp[r - 1][i + 1];
		}
		
		for(int i = r - 2; i >= y; i--) {
			dp[i + 1][c - 1] = dp[i][c - 1];
		}
		
		for(int i = c - 2; i >= 0; i--) {
			dp[y][i + 1] = dp[y][i];
		}
		
		dp[y][1] = 0;
	}
		
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(dp[i][j] > 0) {
				ans += dp[i][j];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> r >> c >> t;
	
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin >> dp[i][j];
			
			if(dp[i][j] == -1) {
				if(x == -1) {
					x = i;
				}
				
				else {
					y = i;
				}
			}
		}
	}
	
	solve();
	
	cout << ans << endl;
}
