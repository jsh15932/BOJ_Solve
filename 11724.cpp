#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, cnt;
int a, b;
bool visited[1001];
vector <int> vc[1001];

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
		cin >> a >> b;
		
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	
	cout << cnt;
}
