#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m;
int a, b;
int ans;
int d[1001];
vector < vector <int> > vc;
bool visited[1001];

bool dfs(int cur) {
	if(visited[cur]) {
		return false;
	}
	
	visited[cur] = true;
	
	for(int i = 0; i < vc[cur].size(); i++) {
		int next = vc[cur][i];
		
		if(!d[next] || dfs(d[next])) {
			d[next] = cur;
			
			return true;
		}
	}
	
	return false;
}

int main() {
	cin >> n >> m;
	vc.resize(1001);
	
	for(int i = 1; i <= n; i++) {
		cin >> a;
		
		for(int j = 1; j <= a; j++) {
			cin >> b;
			
			vc[i].push_back(b);
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 2; j++) {
			memset(visited, false, sizeof(visited));
			
			if(dfs(i)) {
				ans++;
			}
		}
	}
	
	cout << ans;
}
