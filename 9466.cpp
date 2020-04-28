#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool chk[100001];
bool fin[100001];
int vc[100001];
int parent[100001];
int cnt;

void cycle(int v1, int v2) {
	cnt++;
	
	if(v1 == v2) {
		return;
	}
	
	cycle(parent[v1], v2);
}

void dfs(int node) {
	chk[node] = true;
	
	if(!chk[vc[node]]) {
		parent[vc[node]] = node;
		dfs(vc[node]);
	}
	
	else if(!fin[vc[node]]) {
		cycle(node, vc[node]);
	}
	
	fin[node] = true;
}

int main() {
	int tc, n;
	
	cin >> tc;
	
	while(tc--) {
		cin >> n;
		
		cnt = 0;
		
		memset(chk, false, sizeof(chk));
		memset(fin, false, sizeof(fin));
		
		for(int i = 1; i <= n; i++) {
			cin >> vc[i];
		}
		
		for(int i = 1; i <= n; i++) {
			if(!chk[i]) {
				dfs(i);
			}
		}
		
		cout << n - cnt << endl;
	}
}
