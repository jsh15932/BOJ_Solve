#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int map[1001][1001];
queue < pair <int, int> > que;
int cnt, n, m;

int bfs() {
	while(!que.empty()) {
		int q1 = que.front().first;
		int q2 = que.front().second;
		
		que.pop();
		
		for(int i = 0; i < 4; i++) {
			if(q1 + dx[i] >= 0 && q2 + dy[i] >= 0 && q1 + dx[i] < n && q2 + dy[i] < m) {
				if(map[q1 + dx[i]][q2 + dy[i]] == 0) {
					map[q1 + dx[i]][q2 + dy[i]] = map[q1][q2] + 1;
					que.push(make_pair(q1 + dx[i], q2 + dy[i]));
					cnt = map[q1 + dx[i]][q2 + dy[i]];
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
				que.push(make_pair(i, j));
			}
		}
	}
	
	cout << bfs();
}
