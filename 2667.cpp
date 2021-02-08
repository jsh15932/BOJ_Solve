#include<bits/stdc++.h>
using namespace std;

int n, cnt;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int dp[26][26];
vector <int> vc;

void dfs(int x, int y) {
	dp[x][y] = 0;
	
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < n) {
				if(dp[x + dx[i]][y + dy[i]] == 1) {
					cnt++;
					dfs(x + dx[i], y + dy[i]);
				}
			}
		}
	}
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%1d", &dp[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(dp[i][j] == 1) {
				cnt = 1;
				dfs(i, j);
				vc.push_back(cnt);
			}
		}
	}
	
	printf("%d\n", vc.size());
	
	sort(vc.begin(), vc.end());
	
	for(int i = 0; i < vc.size(); i++) {
		printf("%d\n", vc[i]);
	}
}
