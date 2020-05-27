#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t;
int v, e;
int x, y;
vector <int> vc[20001];
int chk[20001];
bool ans;

bool dfs(int node, int set) {
	chk[node] = set;
	
	for(int i = 0; i < vc[node].size(); i++) {
		if(chk[vc[node][i]] == 0) {
			if(!dfs(vc[node][i], -set)) {
				return false;
			}
		}
		
		else if(chk[vc[node][i]] == chk[node]) {
			return false;
		}
	}
	
	return true;
}

int main() {
	cin >> t;
	
	while(t--) {
		ans = true;
		
		cin >> v >> e;
		
		for(int i = 1; i <= v; i++) {
			vc[i].clear();
			chk[i] = 0;
		}
		
		for(int i = 0; i < e; i++) {
			cin >> x >> y;
			
			vc[x].push_back(y);
			vc[y].push_back(x);
		}
		
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
