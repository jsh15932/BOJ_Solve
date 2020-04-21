#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool chk[1001];
vector <int> vc[1001];

void dfs(int node) {
	chk[node] = true;
	
	for(int i = 0; i < vc[node].size(); i++) {
		if(!chk[vc[node][i]]) {
			dfs(vc[node][i]);
		}
	}
}

int main() {
	int n, m;
	int v1, v2;
	int cnt = 0;
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		
		vc[v1].push_back(v2);
		vc[v2].push_back(v1);
	}
	
	for(int i = 1; i <= n; i++) {
		if(!chk[i]) {
			dfs(i);
			cnt++;
		}
	} 
	
	cout << cnt;
}
