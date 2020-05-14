#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m, cnt, ans;
int res, num1, num2;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool visited[9][9], tmp_visited[9][9];
int map[9][9];
queue < pair <int, int> > que;
vector < pair <int, int> > vc;

int bfs() {
	cnt = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			visited[i][j] = tmp_visited[i][j];
		}
	}
	
	for(int i = 0; i < vc.size(); i++) {
		visited[vc[i].first][vc[i].second] = true;
		
		que.push(vc[i]);
	}
	
	while(!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		
		que.pop();
		
		cnt++;
		
		for(int i = 0; i < 4; i++) {
			if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < m && !visited[x + dx[i]][y + dy[i]] && map[x + dx[i]][y + dy[i]] == 0) {
				visited[x + dx[i]][y + dy[i]] = true;
				que.push(make_pair(x + dx[i], y + dy[i]));
			}
		}
	}
	
	return cnt;
}

int Solve() {
	num2 = bfs();
	
	res = n * m - num2 - (num1 + 3);
	
	return res;
}

void dfs(int cnt) {
	if(cnt == 3) {
		ans = max(ans, Solve());
		
		return;
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(map[i][j] == 0) {
				map[i][j] = 1;
				
				dfs(cnt + 1);
				
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> map[i][j];
			
			if(map[i][j] == 2) {
				visited[i][j] = true;
				tmp_visited[i][j] = true;
				
				que.push(make_pair(i, j));
			}
			
			else if(map[i][j] == 1) {
				num1++;
			}
		}
	}
	
	while(!que.empty()) {
		vc.push_back(que.front());
		
		que.pop();
	}
	
	dfs(0);
	
	cout << ans;
}
