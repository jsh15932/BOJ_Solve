#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int graph[100001];
int parent[100001];
bool visited[100001];
bool finished[100001];

int k;
int tc;

void cycle(int v, int p) {
	k++;
	
	if(v == p) {
		return;
	}
	
	cycle(parent[v], p);
}

void dfs(int v) {
	visited[v] = true;
	int next = graph[v];
	
	if(!visited[next]) {
		parent[next] = v;
		dfs(next);
	}
	
	else if(!finished[next]) {
		cycle(v, next);
	}
	
	finished[v] = true;
}

int main() {
	int n;
	
	cin >> tc;
	
	while(tc--) {
		k = 0;
		
		memset(visited, false, sizeof(visited));
		memset(finished, false, sizeof(finished));
		
		cin >> n;
		
		for(int i = 1; i <= n; i++) {
			cin >> graph[i];
		}
		
		for(int i = 1; i <= n; i++) {
			if(!visited[i]) {
				dfs(i);
			}
		}
		cout << n - k << '\n';
	}
}
