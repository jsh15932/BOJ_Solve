#include<iostream>
#include<algorithm>
using namespace std;
#define max 987654321

int n;
int ans = max;
int map[11][11];
bool visited[11];
int start;

void dfs(int node, int cost, int cnt) {
	if(cnt == n - 1) {
		if(map[node][start]) {
			ans = min(ans, cost + map[node][start]);
			return;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if(map[node][i] && visited[i] == false) {
			visited[i] = true;
			dfs(i, cost + map[node][i], cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++) {
		start = i;
		visited[i] = true;
		dfs(i, 0, 0);
		visited[i] = false;
	}
	
	cout << ans;
}
