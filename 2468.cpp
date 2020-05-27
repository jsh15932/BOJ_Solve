#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, h, cnt;
int map[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool visited[101][101];
int res = 0;
int ans = 0;

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
			
			if(map[i][j] > res) {
				res = map[i][j];
			}
		}
	}
	
	for(int i = 0; i <= res; i++) {
		cnt = 0;
		
		memset(visited, false, sizeof(visited));
		
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(map[j][k] > i && !visited[j][k]) {
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
	
	cout << ans;
}
