#include<iostream>
#include<algorithm>
using namespace std;
#define INF 987654321

int n, m;
int a, b;
int ans;
int map[101][101];

void floyd() {
	for(int via = 1; via <= n; via++) {
		for(int from = 1; from <= n; from++) {
			for(int to = 1; to <= n; to++) {
				if(from == to) {
					continue;
				}
				
				if(map[from][via] + map[via][to] < map[from][to]) {
					map[from][to] = map[from][via] + map[via][to];
					map[to][from] = map[from][via] + map[via][to];
				}
			}
		}
	}
}

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
	
	floyd();
	
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
