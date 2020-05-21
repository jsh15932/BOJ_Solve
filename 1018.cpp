#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m;
char c;
int res;
int map[51][51];

int Solve(int n, int m, int color) {
	res = 0;
	
	for(int i = n; i < n + 8; i++) {
		for(int j = m; j < m + 8; j++) {
			if(j % 2 == 0 && map[i][j] != color) {
				res++;
			}
			
			else if(j % 2 == 1 && map[i][j] == color) {
				res++;
			}
		}
		
		color = !color;
	}
	
	return res;
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> c;
			
			if(c == 'W') {
				map[i][j] = 0;
			}
			
			else {
				map[i][j] = 1;
			}
		}
	}
	
	int res = 987654321;
	
	for(int i = 0; i <= n - 8; i++) {
		for(int j = 0; j <= m - 8; j++) {
			res = min(res, Solve(i, j, 0));
			res = min(res, Solve(i, j, 1));
		}
	}
	
	cout << res;
}
