#include<bits/stdc++.h>
using namespace std;

int w, h;
int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};
int dp[51][51];

void dfs(int x, int y) {
	dp[x][y] = 0;
	
	for(int i = 0; i < 8; i++) {
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < w && y + dy[i] < h) {
			if(dp[x + dx[i]][y + dy[i]] == 1) {
				dfs(x + dx[i], y + dy[i]);
			}
		}
	}
}

int main() {
	while(1) {
		scanf("%d %d", &h, &w);
		
		if(w == 0 && h == 0) {
			break;
		}
		
		int cnt = 0;
		
		for(int i = 0; i < w; i++) {
			for(int j = 0; j < h; j++) {
				scanf("%1d", &dp[i][j]);
			}
		}
		
		for(int i = 0; i < w; i++) {
			for(int j = 0; j < h; j++) {
				if(dp[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		
		printf("%d\n", cnt);
	}
}
