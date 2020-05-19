#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int n, num;
int d[101];
bool visited[101];
vector <int> vc;

void dfs(int x, int y) {
	if(x == y) {
		for(int i = 1; i <= n; i++) {
			if(visited[i]) {
				vc.push_back(i);
				d[i] = 0;
			}
		}
		
		return;
	}
	
	if(visited[x] || d[x] == 0) {
		return;
	}
	
	visited[x] = true;
	
	dfs(d[x], y);
}

int main() {
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		cin >> num;
		d[i] = num;
	}
	
	for(int i = 1; i <= n; i++) {
		if(d[i] == 0) {
			continue;
		}
		
		if(d[i] == i) {
			vc.push_back(i);
			continue;
		}
		
		memset(visited, false, sizeof(visited));
		
		visited[i] = true;
		
		dfs(d[i], i);
	}
	
	sort(vc.begin(), vc.end());
	
	cout << vc.size() << '\n';
	
	for(int i = 0; i < vc.size(); i++) {
		cout << vc[i] << endl;
	}
}
