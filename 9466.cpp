#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool chk[100001];
bool fin[100001];
int v[100001];
int parent[100001];
int cnt;
int n, tc;

void cycle(int v1, int v2) {
	cnt++;
	
	if(v1 == v2) {
		return;
	}
	
	cycle(parent[v1], v2);
}

void dfs(int v1) {
	chk[v1] = true;
	
	if(!chk[v[v1]]) {
		parent[v[v1]] = v1;
		dfs(v[v1]);
	}
	
	else if(!fin[v[v1]]) {
		cycle(v1, v[v1]);
	}
	
	fin[v1] = true;
}

int main() {
	cin >> tc;
	
	while(tc--) {
		cin >> n;
		
		cnt = 0;
		
		memset(chk, false, sizeof(chk));
		memset(fin, false, sizeof(fin));
		
		for(int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		
		for(int i = 1; i <= n; i++) {
			if(!chk[i]) {
				dfs(i);
			}
		}
		
		cout << n - cnt << '\n';
	}
}
