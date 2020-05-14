#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, k;
int cnt, num;
int a, b, c, d;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int map[101][101];
bool visited[101][101];
queue < pair <int, int> > que;
vector <int> vc;

void bfs(int x, int y) {
	while(!que.empty()) {
		int q1 = que.front().first;
		int q2 = que.front().second;
		
		que.pop();
		
		for(int i = 0; i < 4; i++) {
			if(q1 + dx[i] >= 0 && q2 + dy[i] >= 0 && q1 + dx[i] < m && q2 + dy[i] < n) {
				if(map[q1 + dx[i]][q2 + dy[i]] == 0 && !visited[q1 + dx[i]][q2 + dy[i]]) {
					que.push(make_pair(q1 + dx[i], q2 + dy[i]));
					visited[q1 + dx[i]][q2 + dy[i]] = true;
					cnt++;
				}
			}
		}
	}
	
	vc.push_back(cnt);
}

int main() {	
	cin >> m >> n >> k;
	
	memset(map, 0, sizeof(map));
	memset(visited, false, sizeof(visited));
	
	for(int i = 0; i < k; i++) {
		cin >> c >> a >> d >> b;
		
		a = m - a;
		b = m - b;
		
		for(int i = c; i < d; i++) {
			for(int j = b; j < a; j++) {
				map[j][i] = 1;
			}
		}
	}
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(map[i][j] == 0 && !visited[i][j]) {
				num++;
				
				cnt = 1;
				que.push(make_pair(i, j));
				visited[i][j] = true;
				
				bfs(i, j);
			}
		}
	}
	
	cout << num << '\n';
	
	sort(vc.begin(), vc.end());
	
	for(int i = 0; i < vc.size(); i++) {
		cout << vc[i] << " ";
	}
}
