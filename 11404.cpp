#include<iostream>
#include<algorithm>
using namespace std;
#define INF 987654321

int n, m;
int a, b, c;
int map[101][101];

void floyd() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(map[j][i] == 0) {
				continue;
			}
			
			for(int k = 1; k <= n; k++) {
				if(map[i][k] == 0 || j == k) {
					continue;
				}
				
				if(map[j][k] == 0 || map[j][k] > map[j][i] + map[i][k]) {
					map[j][k] = map[j][i] + map[i][k];
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		
		if(!map[a][b]) {
			map[a][b] = c;
		}
		
		else {
			map[a][b] = min(map[a][b], c);
		}
	}
	
	floyd();
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << map[i][j] << " ";
		}
		
		cout << endl;
	}
}
