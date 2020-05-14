#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int map[21][21];
bool chk[27];
string s;

int dfs(int x, int y, int k) {
	int res = 0;
	chk[map[x][y]] = true;
	
	for(int i = 0; i < 4; i++) {
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < m) {
			if(!chk[map[x + dx[i]][y + dy[i]]]) {
				res = max(res, dfs(x + dx[i], y + dy[i], k + 1));
			}
		}
	}
	
	chk[map[x][y]] = false;
	
	return res + 1;
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		cin >> s;
		
		for(int j = 0; j < m; j++) {
			map[i][j] = s[j] - 'A';
		}
	}
	
	cout << dfs(0, 0, 1);
}
