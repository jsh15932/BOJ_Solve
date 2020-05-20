#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char map[51][51];
bool visited[51][51];
queue < pair < pair < int, int >, int > > que;
int d;
int ans = 0;

int bfs(int x, int y) {
	while(!que.empty()) {
		int q1 = que.front().first.first;
		int q2 = que.front().first.second;
		int q3 = que.front().second;
		
		que.pop();
		
		for(int i = 0; i < 4; i++) {
			if(q1 + dx[i] >= 0 && q2 + dy[i] >= 0 && q1 + dx[i] < n && q2 + dy[i] < m) {
				if(map[q1 + dx[i]][q2 + dy[i]] == 'L' && !visited[q1 + dx[i]][q2 + dy[i]]) {
					visited[q1 + dx[i]][q2 + dy[i]] = true;
					que.push(make_pair(make_pair(q1 + dx[i], q2 + dy[i]), q3 + 1));
					d = max(d, q3 + 1);
				}
			}
		}
	}
	
	return d;
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%1s", &map[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(map[i][j] == 'L') {
				memset(visited, false, sizeof(visited));
				
				que.push(make_pair(make_pair(i, j), 0));
				visited[i][j] = true;
				d = 0;
				
				ans = max(ans, bfs(i, j));
			}
		}
	}
	
	cout << ans;
}
