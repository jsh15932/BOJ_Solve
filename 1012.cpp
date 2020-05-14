#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k, tc;
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
	cin >> tc;
	
	while(tc--) {
		cin >> n >> m >> k;
		
		cnt = 0;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}
		
		for(int i = 0; i < k; i++) {
			cin >> a >> b;
			
			map[a][b] = 1;
		}
		
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
