#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int map[25][25];
int n;
int cnt;
vector <int> v;

void dfs(int x, int y) {
	map[x][y] = 0;
	
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < n) {
				if(map[x + dx[i]][y + dy[i]] == 1) {
					dfs(x + dx[i], y + dy[i]);
					cnt++;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(map[i][j] == 1) {
				cnt = 1;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}
	
	cout << v.size() << '\n';
	
	sort(v.begin(), v.end());
	
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
