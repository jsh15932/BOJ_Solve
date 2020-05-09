#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int d[101][101];
bool visited[101];
int cnt;
int a, b;

void dfs(int node) {
	cnt++;
	visited[node] = true;
	
	for(int i = 1; i <= n; i++) {
		if(!visited[i] && d[node][i]) {
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
