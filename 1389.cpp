#include<iostream>
#include<algorithm>
using namespace std;
#define INF 987654321

int n, m;
int a, b;
int map[101][101];
int ans;

int main() {
	cin >> n >> m;
	
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			if(i == j) {
				map[i][j] = 0;
			}
			
			else {
				map[i][j] = INF;
			}
		}
	}
	
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		
		map[a][b] = 1;
		map[b][a] = 1;
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				if(j == k) {
					continue;
				}
				
				if(map[j][i] + map[i][k] < map[j][k]) {
					map[j][k] = map[j][i] + map[i][k];
					map[k][j] = map[j][i] + map[i][k];
				}
			}
		}
	}
	
	int min = INF;
	
	for(int i = 1; i <= n; i++) {
		int tmp = 0;
		
		for(int j = 1; j <= n; j++) {
			tmp += map[i][j];
		}
		
		if(tmp < min) {
			min = tmp;
			ans = i;
		}
	}
	
	cout << ans;
}
