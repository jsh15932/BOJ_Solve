#include<bits/stdc++.h>
using namespace std;

int n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int dp[101][101];
bool visited[101][101];

void dfs(int x, int y, int h) {
	for(int i = 0; i < 4; i++) {
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < n) {
			if(dp[x + dx[i]][y + dy[i]] > h && !visited[x + dx[i]][y + dy[i]]) {
				visited[x + dx[i]][y + dy[i]] = true;
				dfs(x + dx[i], y + dy[i], h);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	int res = 0;
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> dp[i][j];
			
			if(dp[i][j] > res) {
				res = dp[i][j];
			}
		}
	}
	
	for(int i = 0; i <= res; i++) {
		int cnt = 0;
		
		memset(visited, false, sizeof(visited));
		
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(dp[j][k] > i && !visited[j][k]) {
					visited[j][k] = true;
					dfs(j, k, i);
					cnt++;
				}
			}
		}
		
		if(cnt > ans) {
			ans = cnt;
		}
	}
	
	cout << ans << endl;
}
