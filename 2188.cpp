#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 987654321

int n, m;
int a, b;
int ans;
bool visited[201];
int d[201];
vector < vector <int> > vc;

int dfs(int cur) {
	if(visited[cur]) {
		return 0;
	}
	
	visited[cur] = true;
	
	for(int i = 0; i < vc[cur].size(); i++) {
		int next = vc[cur][i];
		
		if(!d[next] || dfs(d[next])) {
			d[next] = cur;
			return 1;
		}
	}
	
	return 0;
}

int main() {
	cin >> n >> m;
	
	vc.resize(201);
	
	for(int i = 1; i <= n; i++) {
		cin >> a;
		
		for(int j = 1; j <= a; j++) {
			cin >> b;
			vc[i].push_back(b);
		}
	}
	
	for(int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		
		if(dfs(i)) {
			ans++;
		}
	}
	
	cout << ans;
}
