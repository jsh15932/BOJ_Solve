#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector <int> a[1001];
bool c[1001];

void dfs(int x) {
	if(c[x]) return;
	c[x] = true;
	
	cout << x << ' ';
	
	for(int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		dfs(y);
	}
}

void bfs(int start) {
	queue <int> q;
	q.push(start);
	c[start] = true;
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for(int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if(!c[y]) {
				q.push(y);
				c[y] = true;
 			}
		}
	}
}

int main() {
	int n, m, v;
	cin >> n >> m >> v;
	
	for(int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	for(int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	
	dfs(v);
	
	for(int i = 0; i < 1001; i++) {
		c[i] = 0;
	}
	
	cout << '\n';
	
	bfs(v);
}
