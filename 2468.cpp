#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, res, ans, safe;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int map[101][101];
bool visited[101][101];

void dfs(int x, int y, int h) {
	visited[x][y] = true;
	
	for(int i = 0; i < 4; i++) {
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < n) {
			if(map[x + dx[i]][y + dy[i]] > h && !visited[x + dx[i]][y + dy[i]]) {
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
		safe = 0;
		
		memset(visited, false, sizeof(visited));
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(map[i][j] > h && !visited[i][j]) {
					dfs(i, j, h);
					
					safe++;
				}
			}
		}
		
		ans = max(ans, safe);
	}
	
	cout << ans;
}
