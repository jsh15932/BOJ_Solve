#include<bits/stdc++.h>
using namespace std;

int n, m, ans;
int dp[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
queue < pair < int, int > > que;

void bfs() {
	while(!que.empty()) {
		int q1 = que.front().first;
		int q2 = que.front().second;
		
		que.pop();
		
		for(int i = 0; i < 4; i++) {
		    if(q1 + dx[i] >= 0 && q2 + dy[i] >= 0 && q1 + dx[i] < n && q2 + dy[i] < m) {
				if(dp[q1 + dx[i]][q2 + dy[i]] == 0) {
				    dp[q1 + dx[i]][q2 + dy[i]] = dp[q1][q2] + 1;
				    que.push(make_pair(q1 + dx[i], q2 + dy[i]));
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &m, &n);
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &dp[i][j]);
			
			if(dp[i][j] == 1) {
				que.push(make_pair(i, j));
			}
		}
	}
	
	bfs();
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(dp[i][j] == 0) {
				printf("-1");
				return 0;
			}
			
			if(dp[i][j] > ans) {
				ans = dp[i][j];
			}
		}
	}
	
	printf("%d", ans - 1);
}
