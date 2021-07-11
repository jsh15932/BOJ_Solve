#include<bits/stdc++.h>
using namespace std;

int n, ans;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char c[51][51];
bool visited[51][51];

int Count() {
	int res = 0, cnt = 0;
	char s = '0';
	
	for(int i = 0; i < n; i++) {
		cnt = 1;
		s = c[0][i];
		
		for(int j = 1; j < n; j++) {
			if(s == c[j][i]) {
				cnt++;
			}
			
			else {
				res = max(res, cnt);
				s = c[j][i];
				cnt = 1;
			}
		}
		
		res = max(res, cnt);
		
		cnt = 1;
		s = c[i][0];
		
		for(int j = 1; j < n; j++) {
			if(s == c[i][j]) {
				cnt++;
			}
			
			else {
				res = max(res, cnt);
				s = c[i][j];
				cnt = 1;
			}
		}
		
		res = max(res, cnt);
	}
	
	return res;
}

void Solve(int x, int y) {
	int tmp;
	
	for(int i = 0; i < 4; i++) {
		if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < n) {
			if(!visited[x + dx[i]][y + dy[i]]) {
				tmp = c[x][y];
				c[x][y] = c[x + dx[i]][y + dy[i]];
				c[x + dx[i]][y + dy[i]] = tmp;
				
				ans = max(ans, Count());
				
				tmp = c[x][y];
				c[x][y] = c[x + dx[i]][y + dy[i]];
				c[x + dx[i]][y + dy[i]] = tmp;
			}
		}
	}
	
	visited[x][y] = true;
}

int main() {
	cin >> n;
	
	ans = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> c[i][j];
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			Solve(i, j);
		}
	}
	
	cout << ans << endl;
}