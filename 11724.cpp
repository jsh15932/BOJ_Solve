#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool chk[1001];
vector <int> v[1001];

void dfs(int node) {
	chk[node] = true;
	
	for(int i = 0; i < v[node].size(); i++) {
		int next = v[node][i];
		
		if(!chk[next]) {
			dfs(next);
		}
	}
}

int main() {
	int n, m;
	int a, b;
	int cnt = 0;
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++) {
		if(!chk[i]) {
			dfs(i);
			cnt++;
		}
	}
	
	cout << cnt;
}
