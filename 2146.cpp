#include<iostream>
#include<algorithm>
using namespace std;

int map[101][101];
bool d[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n;
int cnt = 2;
int ans = 1000;

void dfs(int x, int y) {
	map[x][y] = cnt;
	
	for(int i = 0; i < 4; i++) {
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < n) {
			if(map[x + dx[i]][y + dy[i]] == 0) {
				d[x][y] = true;
			}
			
			if(map[x + dx[i]][y + dy[i]] == 1) {
				dfs(x + dx[i], y + dy[i]);
			}
		}
	}
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(map[i][j] == 1) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(d[i][j] == 1) {
				for(int k = i; k <= min(n - 1, i + ans); k++) {
					for(int l = max(0, j - ans); l <= min(n - 1, j + ans); l++) {
						if(map[i][j] != map[k][l] && d[k][l] == 1) {
							ans = min(ans, abs(i - k) + abs(j - l) - 1);
						}
					}
				}
			}
		}
	}
	
	cout << ans;
}
