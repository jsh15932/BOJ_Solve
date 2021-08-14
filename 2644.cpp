#include<bits/stdc++.h>
using namespace std;

int n, x, y, m;
vector<int> vc[101];
int d[101];

int bfs() {
	queue<int> que;
	que.push(x);
	
	while(!que.empty()) {
		int cur = que.front();
		que.pop();
		
		if(cur == y) {
			return d[cur];
		}
		
		for(int i = 0; i < vc[cur].size(); i++) {
			int next = vc[cur][i];
			
			if(d[next]) {
				continue;
			}
			
			que.push(next);
			d[next] = d[cur] + 1;
		}
	}
	
	return -1;
}

int main() {
	cin >> n >> x >> y >> m;
	
	for(int i = 0; i < m; i++) {
		int a, b;
		
		cin >> a >> b;
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	
	cout << bfs() << endl;
}