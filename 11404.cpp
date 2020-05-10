#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int from, to, cost;
int map[101][101];

void floyd() {
	for(int via = 1; via <= n; via++) {
		for(int from = 1; from <= n; from++) {
			for(int to = 1; to <= n; to++) {
				if(map[from][via] == 0 || map[via][to] == 0 || from == to) {
					continue;
				}
				
				if(map[from][to] == 0 || map[from][via] + map[via][to] < map[from][to]) {
					map[from][to] = map[from][via] + map[via][to];
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		
		if(map[from][to]) {
			map[from][to] = min(map[from][to], cost);
		}
		
		else {
			map[from][to] = cost;
		}
	}
	
	floyd();
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << map[i][j] << ' ';
		}
		
		cout << endl;
	}
}
