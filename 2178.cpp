#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int map[101][101];
int chk[101][101];
int visited[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
queue < pair <int, int> > que;
int n, m;

void bfs() {
	while(!que.empty()) {
		int q1 = que.front().first;
		int q2 = que.front().second;
		
		que.pop();
		
		for(int i = 0; i < 4; i++) {
			if(q1 + dx[i] >= 0 && q2 + dy[i] >= 0 && q1 + dx[i] < n && q2 + dy[i] < m) {
				if(map[q1 + dx[i]][q2 + dy[i]] == 1 && visited[q1 + dx[i]][q2 + dy[i]] == 0) {
					que.push(make_pair(q1 + dx[i], q2 + dy[i]));
					visited[q1 + dx[i]][q2 + dy[i]] = 1;
					chk[q1 + dx[i]][q2 + dy[i]] = chk[q1][q2] + 1;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			visited[i][j] = 0;
		}
	}
	
	que.push(make_pair(0, 0));
	chk[0][0] = 1;
	
	bfs();
	
	cout << chk[n - 1][m - 1];
}
