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

void dfs(int v1) {
	chk[v1] = true;
	
	if(!chk[vc[v1]]) {
		parent[vc[v1]] = v1;
		dfs(vc[v1]);
	}
	
	else if(!fin[vc[v1]]) {
		cycle(v1, vc[v1]);
	}
	
	fin[v1] = true;
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
		
		cout << n - cnt << '\n';
	}
}
