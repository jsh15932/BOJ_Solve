#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int map[1001][1001];
int c[1001][1001][2];
queue < pair < pair < int, int >, int > > que;
string s;

int bfs() {
	while(!que.empty()) {
		int q1 = que.front().first.first;
		int q2 = que.front().first.second;
		int q3 = que.front().second;
		
		que.pop();
		
		if(q1 == n - 1 && q2 == m - 1) {
			return c[q1][q2][q3];
		}
		
		for(int i = 0; i < 4; i++) {
			if(q1 + dx[i] >= 0 && q2 + dy[i] >= 0 && q1 + dx[i] < n && q2 + dy[i] < m) {
				if(map[q1 + dx[i]][q2 + dy[i]] == 1 & q3) {
					c[q1 + dx[i]][q2 + dy[i]][q3 - 1] = c[q1][q2][q3] + 1;
					que.push(make_pair(make_pair(q1 + dx[i], q2 + dy[i]), q3 - 1));
				}
				
				else if(map[q1 + dx[i]][q2 + dy[i]] == 0 && c[q1 + dx[i]][q2 + dy[i]][q3] == 0) {
					c[q1 + dx[i]][q2 + dy[i]][q3] = c[q1][q2][q3] + 1;
					que.push(make_pair(make_pair(q1 + dx[i], q2 + dy[i]), q3));
				}
			}
		}
	}
	
	return -1;
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		cin >> s;
		
		for(int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}
	
	que.push(make_pair(make_pair(0, 0), 1));
	c[0][0][1] = 1;
	
	cout << bfs();
}
