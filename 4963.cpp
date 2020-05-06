#include<iostream>
#include<algorithm>
using namespace std;

int w, h;
int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};
int map[51][51];
int cnt;

void dfs(int x, int y) {
	map[x][y] = 0;
	
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < w && y + dy[i] < h) {
				if(map[x + dx[i]][y + dy[i]] == 1) {
					dfs(x + dx[i], y + dy[i]);
				}
			}
		}
	}
}

int main() {
	while(1) {
		cin >> h >> w;
		
		cnt = 0;
		
		if(w == 0 && h == 0) {
			break;
		}
		
		for(int i = 0; i < w; i++) {
			for(int j = 0; j < h; j++) {
				scanf("%1d", &map[i][j]);
			}
		}
		
		for(int i = 0; i < w; i++) {
			for(int j = 0; j < h; j++) {
				if(map[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		
		cout << cnt << endl;
	}
}
