#include<iostream>
#include<algorithm>
using namespace std;

int map[26][26];
int size[626];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int cnt;
int n;

bool inside(int a, int b) {
	return (a >= 0 & a < n) && (b >= 0 & b < n);
}

void dfs(int a, int b, int key) {
	map[a][b] = key;
	
	for(int i = 0; i < 4; i++) {
		int dy = a + dir[i][0];
		int dx = b + dir[i][1];
		
		if(inside(dy, dx) && map[dy][dx] == 1) {
			dfs(dy, dx, key);
		}
	}
}

void Solve(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(map[i][j] == 1) {
				cnt++;
				dfs(i, j, cnt + 1);
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(map[i][j] > 1) {
				size[map[i][j] - 2]++;
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
	
	Solve(n);
	
	sort(size, size + cnt);
	
	cout << cnt << '\n';
	
	for(int i = 0; i < cnt; i++) {
		cout << size[i] << endl;
	}
}
