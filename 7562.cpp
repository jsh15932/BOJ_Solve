#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int t, n;
int cur_x, cur_y;
int end_x, end_y;
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int map[301][301];
bool visited[301][301];
queue < pair <int, int> > que;

void bfs() {
	while(!que.empty()) {
		int q1 = que.front().first;
		int q2 = que.front().second;
		
		que.pop();
		
		for(int i = 0; i < 8; i++) {
			if(q1 + dx[i] >= 0 && q2 + dy[i] >= 0 && q1 + dx[i] < n && q2 + dy[i] < n) {
				if(!visited[q1 + dx[i]][q2 + dy[i]]) {
					visited[q1 + dx[i]][q2 + dy[i]] = true;
					que.push(make_pair(q1 + dx[i], q2 + dy[i]));
					map[q1 + dx[i]][q2 + dy[i]] = map[q1][q2] + 1;
				}
			}
		}
	}
}

int main() {
	cin >> t;
	
	while(t--) {
		cin >> n;
		
		cin >> cur_x >> cur_y;
		cin >> end_x >> end_y;
		
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		
		que.push(make_pair(cur_x, cur_y));
		visited[cur_x][cur_y] = true;
		
		bfs();
		
		cout << map[end_x][end_y] << endl;
	}
}
