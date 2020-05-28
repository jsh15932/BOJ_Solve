#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, res;
int bx, by, rx, ry;
int dis[11][11][11][11];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char c[11][11];
bool visited[11][11][11][11];
queue < pair < pair < int, int >, pair < int, int > > > que;

int bfs() {
	while(!que.empty()) {
		int size = que.size();
		
		while(size--) {
			int q1 = que.front().first.first;
			int q2 = que.front().first.second;
			int q3 = que.front().second.first;
			int q4 = que.front().second.second;
			
			que.pop();
			
			if(c[q1][q2] == 'O' && c[q1][q2] != c[q3][q4]) {
				return res;
			}
			
			for(int i = 0; i < 4; i++) {
				int c_q1 = q1;
				int c_q2 = q2;
				int c_q3 = q3;
				int c_q4 = q4;
				
				while(c[c_q1][c_q2] != 'O' && c[c_q1 + dx[i]][c_q2 + dy[i]] != '#') {
					c_q1 += dx[i];
					c_q2 += dy[i];
				}
				
				while(c[c_q3][c_q4] != 'O' && c[c_q3 + dx[i]][c_q4 + dy[i]] != '#') {
					c_q3 += dx[i];
					c_q4 += dy[i];
				}
				
				if(c_q1 == c_q3 && c_q2 == c_q4) {
					if(c[c_q1][c_q2] == 'O') {
						continue;
					}
					
					if(abs(c_q1 - q1) + abs(c_q2 - q2) < abs(c_q3 - q3) + abs(c_q4 - q4)) {
						c_q3 -= dx[i];
						c_q4 -= dy[i];
					}
					
					else {
						c_q1 -= dx[i];
						c_q2 -= dy[i];
					}
				}
				
				if(dis[c_q1][c_q2][c_q3][c_q4]) {
					continue;
				}
				
				que.push(make_pair(make_pair(c_q1, c_q2), make_pair(c_q3, c_q4)));
				dis[c_q1][c_q2][c_q3][c_q4] = 1;
			}
		}
		
		if(res == 10) {
			return -1;
		}
		
		res++;
	}
	
	return -1;
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		getchar();
		
		for(int j = 0; j < m; j++) {
			cin >> c[i][j];
			
			if(c[i][j] == 'B') {
				bx = i;
				by = j;
			}
			
			else if(c[i][j] == 'R') {
				rx = i;
				ry = j;
			}
		}
	}
	
	que.push(make_pair(make_pair(rx, ry), make_pair(bx, by)));
	dis[rx][ry][bx][by] = 1;
	
	cout << bfs();
}
