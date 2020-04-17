#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int d[25][25];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
vector <int> v;
int cnt;
int n;

void dfs(int x, int y) {
	d[x][y] = 0;
	cnt++;
	
	for(int i = 0; i < 4; i++) {
		if(x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= n || y + dy[i] >= n) {
			continue;
		}
		
		if(d[x + dx[i]][y + dy[i]] == 0) {
			continue;
		}
		
		dfs(x + dx[i], y + dy[i]);
	}
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%1d", &d[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(d[i][j] == 1) {
				cnt = 0;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}
	
	sort(v.begin(), v.end());
	
	cout << v.size() << '\n';
	
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
