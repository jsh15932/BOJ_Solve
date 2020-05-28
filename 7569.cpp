#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, m, h, ans;
int map[101][101][101];
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
queue < pair < pair < int, int >, int > > que;

void bfs() {
	while(!que.empty()) {
		int q1 = que.front().first.first;
		int q2 = que.front().first.second;
		int q3 = que.front().second;
		
		que.pop();
		
		for(int i = 0; i < 6; i++) {
			if(q1 + dx[i] >= 0 && q2 + dy[i] >= 0 && q3 + dz[i] >= 0 && q1 + dx[i] < h && q2 + dy[i] < n && q3 + dz[i] < m) {
				if(map[q1 + dx[i]][q2 + dy[i]][q3 + dz[i]] == 0) {
					map[q1 + dx[i]][q2 + dy[i]][q3 + dz[i]] = map[q1][q2][q3] + 1;
					que.push(make_pair(make_pair(q1 + dx[i], q2 + dy[i]), q3 + dz[i]));
				}
			} 
		}
	}
}

int main() {
	cin >> m >> n >> h;
	
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < m; k++) {
				cin >> map[i][j][k];
				
				if(map[i][j][k] == 1) {
					que.push(make_pair(make_pair(i, j), k));
				}
			}
		}
	}
	
	bfs();
	
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < m; k++) {
				if(map[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				
				if(map[i][j][k] > ans) {
					ans = map[i][j][k];
				}
			}
		}
	}
	
	cout << ans - 1;
}
