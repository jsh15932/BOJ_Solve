#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int t, n, m, k;
int a, b;
int cnt;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int map[51][51];
bool visited[51][51];

void dfs(int x, int y) {
	for(int i = 0; i < 4; i++) {
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < m) {
			if(map[x + dx[i]][y + dy[i]] == 1 && !visited[x + dx[i]][y + dy[i]]) {
				visited[x + dx[i]][y + dy[i]] = true;
				dfs(x + dx[i], y + dy[i]);
			}
		}
	}
}

int main() {
	cin >> t;
	
	while(t--) {
		cnt = 0;
		
		memset(map, 0, sizeof(map));

		cin >> n >> m >> k;
		
		for(int i = 0; i < k; i++) {
			cin >> a >> b;
			
			map[a][b] = 1;
		}
		
		memset(visited, false, sizeof(visited));
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(map[i][j] == 1 && !visited[i][j]) {
					visited[i][j] = true;
					dfs(i, j);
					cnt++;
				}
			}
		}
		
		cout << cnt << endl;
	}
}
