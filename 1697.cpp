#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define max 100001

int n, k;
int ans, res;
int dx[] = {-1, 0, 1};
bool visited[max];
queue < pair <int, int> > que;

void bfs(int x) {
	while(!que.empty()) {
		int q1 = que.front().first;
		int q2 = que.front().second;
		
		que.pop();
		
		if(q1 == k) {
			ans = q2;
			return;
		}
		
		for(int i = 0; i < 3; i++) {
			if(dx[i] == 0) {
				res = q1 * 2;
			}
			
			else {
				res = q1 + dx[i];
			}
			
			if(res < 0 || res >= max || visited[res]) {
				continue;
			}
			
			que.push(make_pair(res, q2 + 1));
			visited[res] = true;
		}
	}
}

int main() {
	cin >> n >> k;
	
	que.push(make_pair(n, 0));
	visited[n] = true;
	
	bfs(n);
	
	cout << ans;
}
