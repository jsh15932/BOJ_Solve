#include<bits/stdc++.h>
using namespace std;

int n, k, res;
int dx[] = {-1, 0, 1};
bool visited[100001];
queue < pair < int, int > > que;

int bfs(int x) {
	while(!que.empty()) {
		int q1 = que.front().first;
		int q2 = que.front().second;
		
		que.pop();
		
		if(q1 == k) {
			return q2;
		}
		
		for(int i = 0; i < 3; i++) {
			if(dx[i] == 0) {
				res = q1 * 2;
			}
			
			else {
				res = q1 + dx[i];
			}
			
			if(res < 0 || res > 100000 || visited[res]) {
				continue;
			}
			
			que.push(make_pair(res, q2 + 1));
			visited[res] = true;
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	
	que.push(make_pair(n, 0));
	visited[n] = true;
	
	printf("%d", bfs(n));
}
