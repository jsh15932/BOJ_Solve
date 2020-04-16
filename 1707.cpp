#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector <int> a[20001];
int chk[20001];

bool dfs(int node, int set) {
	chk[node] = set;
	
	for(int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		
		if(chk[next] == 0) {
			if(!dfs(next, -set)) {
				return false;
			}
		}
		
		else if(chk[next] == chk[node]) {
			return false;
		}
	}
	
	return true;
}

int main() {
	int tc;
	int v, e;
	int x, y;

	cin >> tc;
	
	while(tc--) {
		cin >> v >> e;
		
		for(int i = 1; i <= v; i++) {
			a[i].clear();
			chk[i] = 0;
		}
		
		for(int i = 0; i < e; i++) {
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		
		bool ans = true;
		
		for(int i = 1; i <= v; i++) {
			if(chk[i] == 0) {
				if(!dfs(i, 1)) {
					ans = false;
					break;
				}
			}
		}
		
		printf("%s\n", ans ? "YES" : "NO");
	}
}
