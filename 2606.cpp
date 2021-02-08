#include<bits/stdc++.h>
using namespace std;

int n, m;
int a, b;
int d[101][101];
int cnt;
bool visited[101];

void dfs(int x) {
	cnt++;
	visited[x] = true;
	
	for(int i = 1; i <= n; i++) {
		if(d[x][i] == 1 && !visited[i]) {
			dfs(i);
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		
		d[a][b] = 1;
		d[b][a] = 1;
	}
	
	dfs(1);
	
	cout << cnt - 1;
}
