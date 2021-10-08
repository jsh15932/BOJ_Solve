#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vc;
vector< vector<int> > a;

void bfs() {
	queue<int> que;
	
	for(int i = 1; i <= n; i++) {
		if(vc[i] == 0) {
			que.push(i);
		}
	}
	
	while(!que.empty()) {
		int cur = que.front();
		que.pop();
		
		cout << cur << " ";
		
		int len = a[cur].size();
		
		for(int i = 0; i < len; i++) {
			int k = a[cur][i];
			
			if(--vc[k] == 0) {
				que.push(k);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	vc.resize(n + 1);
	a.resize(n + 1);
	
	while(m--) {
		int x, y;
		
		cin >> x >> y;
		
		a[x].push_back(y);
		vc[y]++;
	}
	
	bfs();
	
	cout << endl;
}