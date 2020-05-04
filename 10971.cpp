#include<iostream>
#include<algorithm>
using namespace std;

int map[11][11];
bool chk[11];
int n;
int m = 987654321;

void dfs(int x, int y, int sum, int cnt) {
	if(cnt == n && x == y) {
		if(m > sum) {
			m = sum;
		}
		
		return;
	}
	
	for(int i = 0; i < n; i++) {
		if(map[y][i] == 0) {
			continue;
		}
		
		if(!chk[y] && map[y][i] > 0) {
			chk[y] = true;
			sum += map[y][i];
			
			if(sum <= m) {
				dfs(x, i, sum, cnt + 1);
			}
			
			chk[y] = false;
			sum -= map[y][i];
		}
	}
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	for(int i = 0; i < n; i++) {
		dfs(i, i, 0, 0);
	}
	
	cout << m;
}
