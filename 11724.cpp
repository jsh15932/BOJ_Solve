#include<bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector <int> vc[1001];
bool visited[1001];

void dfs(int x) {
	visited[x] = true;
	
	for(int i = 0; i < vc[x].size(); i++) {
		if(!visited[vc[x][i]]) {
			dfs(vc[x][i]);
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	
	int cnt = 0;
	
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	
	printf("%d", cnt);
}
