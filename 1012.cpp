#include<bits/stdc++.h>
using namespace std;

int t, n, m, k, x, y;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int dp[51][51];
bool visited[51][51];

void dfs(int a, int b) {
	for(int i = 0; i < 4; i++) {
		if(a + dx[i] >= 0 && b + dy[i] >= 0 && a + dx[i] < n && b + dy[i] < m) {
			if(dp[a + dx[i]][b + dy[i]] == 1 && !visited[a + dx[i]][b + dy[i]]) {
				visited[a + dx[i]][b + dy[i]] = true;
				dfs(a + dx[i], b + dy[i]);
			}
		}
	}
}

int main() {
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d %d %d", &n, &m, &k);
		
		int cnt = 0;
		
		memset(dp, 0, sizeof(dp));
		memset(visited, false, sizeof(visited));
		
		for(int i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			
			dp[x][y] = 1;
		}
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(dp[i][j] == 1 && !visited[i][j]) {
					visited[i][j] = true;
					dfs(i, j);
					cnt++;
				}
			}
		}
		
		printf("%d\n", cnt);
	}
}
