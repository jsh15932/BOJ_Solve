#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m;
int map[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char c[51][51];
bool visited[51][51];
int cnt, res;

bool dfs(int x, int y, int cnt) {
	if(res == -1) {
		return true;
	}
	
	if(cnt > res) {
		res = cnt;
	}
	
	visited[x][y] = true;
	map[x][y] = cnt;
	
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i] * (c[x][y] - '0');
		int ny = y + dy[i] * (c[x][y] - '0');
		
		if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if(c[nx][ny] != 'H') {
				if(visited[nx][ny]) {
					res = -1;
					return true;
				}
				
				if(map[nx][ny] && cnt < map[nx][ny]) {
					continue;
				}
				
				if(dfs(nx, ny, cnt + 1)) {
					return true;
				}
			}
		}
	}
	
	visited[x][y] = false;
	
	return false;
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++, getchar()) {
		for(int j = 0; j < m; j++) {
			cin >> c[i][j];
		}
	}
	
	dfs(0, 0, 1);
	
	cout << res;
}
