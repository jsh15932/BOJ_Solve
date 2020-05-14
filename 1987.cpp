#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int r, c;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int map[21][21];
bool check[27];
string s;

int dfs(int x, int y, int k) {
	int res = 0;
	check[map[x][y]] = true;
	
	for(int i = 0; i < 4; i++) {
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < r && y + dy[i] < c && !check[map[x + dx[i]][y + dy[i]]]) {
			res = max(res, dfs(x + dx[i], y + dy[i], k + 1));
		}
	}
	
	check[map[x][y]] = false;
	
	return res + 1;
}

int main() {
	cin >> r >> c;
	
	for(int i = 0; i < r; i++) {
		cin >> s;
		
		for(int j = 0; j < c; j++) {
			map[i][j] = s[j] - 'A';
		}
	}
	
	cout << dfs(0, 0, 1);
}
