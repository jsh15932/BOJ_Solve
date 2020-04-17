#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int map[1001][1001];
int n, m;
int cnt;
queue < pair <int, int> > q;

int bfs() {
	while(!q.empty()) {
		int x, y;
		x = q.front().first;
		y = q.front().second;
		
		q.pop();
		
		for(int i = 0; i < 4; i++) {
			if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < m) {
				if(map[x + dx[i]][y + dy[i]] == 0) {
					map[x + dx[i]][y + dy[i]] = map[x][y] + 1;
					q.push(make_pair(x + dx[i], y + dy[i]));
					cnt = map[x + dx[i]][y + dy[i]];
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(map[i][j] == 0) {
				return -1;
			}
		}
	}
	
	if(cnt == 0) {
		return 0;
	}
	
	return cnt - 1;
}

int main() {
	cin >> m >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> map[i][j];
			
			if(map[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
	
	cout << bfs();
}
