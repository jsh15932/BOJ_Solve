#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int map[26][26];
int cnt, n;
vector <int> vc;

void dfs(int x, int y) {
	map[x][y] = 0;
	
	for(int i = 0; i < 4; i++) {
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < n) {
		    if(map[x + dx[i]][y + dy[i]] == 1) {
			dfs(x + dx[i], y + dy[i]);
			cnt++;
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
				vc.push_back(cnt);
			}
		}
	}
	
	cout << vc.size() << '\n';
	
	sort(vc.begin(), vc.end());
	
	for(int i = 0; i < vc.size(); i++) {
		cout << vc[i] << endl;
	}
}
