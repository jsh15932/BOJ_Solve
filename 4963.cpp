#include<iostream>
#include<algorithm>
using namespace std;

int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};
int map[51][51];
int n, m;
int cnt;

void dfs(int x, int y) {
	map[x][y] = 0;
	
	for(int i = 0; i < 8; i++) {
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < m) {
			if(map[x + dx[i]][y + dy[i]] == 1){
				dfs(x + dx[i], y + dy[i]);
			}
		}
	}
}

int main() {
	while(1) {
		cin >> m >> n;
		
		if(n == 0 & m == 0) {
			break;
		}
		
		cnt = 0;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> map[i][j];
			}
		}
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(map[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		
		cout << cnt << endl;
	}
}
