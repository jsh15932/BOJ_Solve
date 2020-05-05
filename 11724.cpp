#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
bool visited[1001];
vector <int> vc[1001];
int cnt;

void dfs(int node) {
	visited[node] = true;
	
	for(int i = 0; i < vc[node].size(); i++) {
		if(!visited[vc[node][i]]) {
			dfs(vc[node][i]);
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++) {
		int v1, v2;
		
		cin >> v1 >> v2;
		
		vc[v1].push_back(v2);
		vc[v2].push_back(v1);
	}
	
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	
	cout << cnt;
}
