#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vc[501];
bool chk[501];
queue<int> que;

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		int x, y;
		
		cin >> x >> y;
		vc[x].push_back(y);
		vc[y].push_back(x);
		
		if(x == 1) {
			que.push(y);
			chk[y] = true;
		}
		
		else if(y == 1) {
			que.push(x);
			chk[x] = true;
		}
	}
	
	int ans = que.size();
	chk[1] = true;
	
	while(!que.empty()) {
		int q1 = que.front();
		que.pop();
		
		for(int i = 0; i < vc[q1].size(); i++) {
			if(chk[vc[q1][i]]) {
				continue;
			}
			
			chk[vc[q1][i]] = true;
			ans++;
		}
	}
	
	cout << ans << endl;
}