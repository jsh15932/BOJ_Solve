#include<bits/stdc++.h>
using namespace std;

int n, m;
int dp[101][101];
int cnt[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool visited[101][101];
queue < pair < int, int > > que;

void bfs() {
	while(!que.empty()) {
		int q1 = que.front().first;
		int q2 = que.front().second;
		
		que.pop();
		
		for(int i = 0; i < 4; i++) {
			if(q1 + dx[i] >= 0 && q2 + dy[i] >= 0 && q1 + dx[i] < n && q2 + dy[i] < m) {
				if(dp[q1 + dx[i]][q2 + dy[i]] == 1 && !visited[q1 + dx[i]][q2 + dy[i]]) {
					visited[q1 + dx[i]][q2 + dy[i]] = true;
					que.push(make_pair(q1 + dx[i], q2 + dy[i]));
					cnt[q1 + dx[i]][q2 + dy[i]] = cnt[q1][q2] + 1;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%1d", &dp[i][j]);
		}
	}
	
	que.push(make_pair(0, 0));
	visited[0][0] = true;
	cnt[0][0] = 1;
	
	bfs();
	
	printf("%d", cnt[n - 1][m - 1]);
}
