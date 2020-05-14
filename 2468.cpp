#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, res, ans, cnt;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int map[101][101];
bool visited[101][101];

void dfs(int x, int y, int h) {
	for(int i = 0; i < 4; i++) {
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < n) {
			if(map[x + dx[i]][y + dy[i]] > h && !visited[x + dx[i]][y + dy[i]]) {
				visited[x + dx[i]][y + dy[i]] = true;
				dfs(x + dx[i], y + dy[i], h);
			}
		}
	}
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> map[i][j];
			
			res = max(res, map[i][j]);
		}
	}
	
	for(int h = 0; h <= res; h++) {
		cnt = 0;
		
		memset(visited, false, sizeof(visited));
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(map[i][j] > h && !visited[i][j]) {
					visited[i][j] = true;
					dfs(i, j, h);
					cnt++;
				}
			}
		}
		
		ans = max(ans, cnt);
	}
	
	cout << ans;
}
