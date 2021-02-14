#include<bits/stdc++.h>
using namespace std;

int n, m, res;
int bx, by, rx, ry;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int dp[11][11][11][11];
char s[11][11];
bool visited[11][11][11][11];
queue < pair < pair < int, int >, pair < int, int > > > que;

int bfs() {
	while(!que.empty()) {
		int size = que.size();
		
		while(size--) {
			int q1 = que.front().first.first;
			int q2 = que.front().first.second;
			int q3 = que.front().second.first;
			int q4 = que.front().second.second;
			
			que.pop();
			
			if(s[q1][q2] == 'O' && s[q1][q2] != s[q3][q4]) {
				return res;
			}
			
			for(int i = 0; i < 4; i++) {
				int nq1 = q1;
				int nq2 = q2;
				int nq3 = q3;
				int nq4 = q4;
				
				while(s[nq1][nq2] != 'O' && s[nq1 + dx[i]][nq2 + dy[i]] != '#') {
					nq1 += dx[i];
					nq2 += dy[i];
				}
				
				while(s[nq3][nq4] != 'O' && s[nq3 + dx[i]][nq4 + dy[i]] != '#') {
					nq3 += dx[i];
					nq4 += dy[i];
				}
				
				if(nq1 == nq3 && nq2 == nq4) {
					if(s[nq1][nq2] == 'O') {
						continue;
					}
					
					if(abs(nq1 - q1) + abs(nq2 - q2) > abs(nq3 - q3) + abs(nq4 - q4)) {
						nq1 -= dx[i];
						nq2 -= dy[i];
					}
					
					else {
						nq3 -= dx[i];
						nq4 -= dy[i];
					}
				}
				
				if(dp[nq1][nq2][nq3][nq4]) {
					continue;
				}
				
				que.push(make_pair(make_pair(nq1, nq2), make_pair(nq3, nq4)));
				dp[nq1][nq2][nq3][nq4] = 1;
			}
		}
		
		if(res == 10) {
			return -1;
		}
		
		res++;
	}
	
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> s[i][j];
			
			if(s[i][j] == 'B') {
				bx = i;
				by = j;
			}
			
			else if(s[i][j] == 'R') {
				rx = i;
				ry = j;
			}
		}
	}
	
	que.push(make_pair(make_pair(rx, ry), make_pair(bx, by)));
	dp[rx][ry][bx][by] = 1;
	
	cout << bfs() << endl;
}
