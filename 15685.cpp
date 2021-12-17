#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, m;
int arr[51][51];
int res;
vector< pair<int, int> > vc;
bool visited[51][51];

void find() {
	int tmp = 0;
	memset(visited, false, sizeof(visited));
	
	while(1) {
		int sum = INF;
		int x = -1, y = -1;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(arr[i][j] == 1 & !visited[i][j]) {
					visited[i][j] = true;
					x = j;
					y = i;
					
					break;
				}
			}
			
			if(y != -1) {
				break;
			}
		}
		
		if(x == -1 && y == -1) {
			break;
		}
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(arr[i][j] == 2) {
					sum = min(sum, abs(y - i) + abs(x - j));
				}
			}
		}
		
		tmp += sum;
	}
	
	res = min(res, tmp);
}

void solve(vector<bool>& visited, int start) {
	int cnt = 0;
	
	for(int i = 0; i < vc.size(); i++) {
		if(visited[i]) {
			cnt++;
		}
	}
	
	if(cnt == m) {
		for(int i = 0; i < vc.size(); i++) {
			if(visited[i]) {
				int y = vc[i].first;
				int x = vc[i].second;
				arr[y][x] = 2;
			}
		}
		
		find();
	
		for(int i = 0; i < vc.size(); i++) {
			if(visited[i]) {
				int y = vc[i].first;
				int x = vc[i].second;
				arr[y][x] = 0;
			}
		}
		
		return;
	}
	
	for(int i = start; i < vc.size(); i++) {
		if(!visited[i]) {
			visited[i] = true;
			solve(visited, i);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[i][j];
			
			if(arr[i][j] == 2) {
				vc.push_back({ i, j });
				arr[i][j] = 0;
			}
		}
	}
	
	vector<bool> visited(13, false);
	res = INF;
	
	solve(visited, 0);
	
	cout << res << endl;
}