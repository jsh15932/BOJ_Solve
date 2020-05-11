#include<iostream>
#include<algorithm>
using namespace std;
#define INF 987654321

int n, m;
int a, b;
int ans;
int map[501][501];
int chk[501];

void floyd() {
	for(int via = 1; via <= n; via++) {
		for(int from = 1; from <= n; from++) {
			for(int to = 1; to <= n; to++) {
				if(map[from][via] + map[via][to] < map[from][to]) {
					map[from][to] = map[from][via] + map[via][to];
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			map[i][j] = INF;
		}
	}
	
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	
	floyd();
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(map[i][j] != INF) {
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
