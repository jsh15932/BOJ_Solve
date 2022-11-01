#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m;
int x, y;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char map[51][51];
int d[51][51];
queue < pair < pair < int, int >, int > > que;

void bfs() {
	que.push({{ x, y }, 1});
	d[x][y] = 1;
	
	while(!que.empty()) {
		int q1 = que.front().first.first;
		int q2 = que.front().first.second;
		int q3 = que.front().second;
		
		que.pop();
		
		for(int i = 0; i < 4; i++) {
			if(q1 + dx[i] >= 0 && q2 + dy[i] >= 0 && q1 + dx[i] < n && q2 + dy[i] < m) {
				if(map[q1 + dx[i]][q2 + dy[i]] != 'X' && d[q1 + dx[i]][q2 + dy[i]] == 0) {
					if(map[q1 + dx[i]][q2 + dy[i]] == 'D') {
					    if(q3 == 0) {
						    continue;
					    }
					
					    cout << d[q1][q2];
					    return;
				    }
				
				    d[q1 + dx[i]][q2 + dy[i]] = d[q1][q2] + 1;
				    que.push(make_pair(make_pair(q1 + dx[i], q2 + dy[i]), q3));
				}
			}
		}
	}
	
	cout << "KAKTUS";
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%1s", &map[i][j]);
			
			if(map[i][j] == '*') {
				que.push({{i, j}, 0});
				d[i][j] = 1;
			}
			
			else if(map[i][j] == 'S') {
				x = i;
				y = j;
			}
		}
	}
	
	bfs();
}