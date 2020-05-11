#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int a, b;
int ans;
int map[501][501] = {0, };
int chk[501];

void floyd() {
	for(int via = 1; via <= n; via++) {
		for(int from = 1; from <= n; from++) {
			for(int to = 1; to <= n; to++) {
				if(map[from][via] && map[via][to]) {
					map[from][to] = 1;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			map[i][j] = 0;
		}
	}
	
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	
	floyd();
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(map[i][j] == 1) {
				chk[i]++;
				chk[j]++;
				
				if(chk[i] == n - 1) {
					ans++;
				}
				
				if(chk[j] == n - 1) {
					ans++;
				}
			}
		}
	}
	
	cout << ans;
}
