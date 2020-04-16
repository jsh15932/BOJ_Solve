#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector <int> a[1001];
bool chk[1001];

void dfs(int node) {
	chk[node] = true;
	
	for(int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if(!chk[next]) {
			dfs(next);
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	
	int cnt = 0;
	
	for(int i = 1; i <= n; i++){
		if(!chk[i]) {
			dfs(i);
			cnt++;
		}
	}
	
	cout << cnt;
}
