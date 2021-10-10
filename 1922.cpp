#include<bits/stdc++.h>
using namespace std;

int n, m;
vector< pair<int, int> > vc[1001];
bool visited[1001];

int main() {
	cin >> n >> m;
	
	int res = 0;
	
	for(int i = 0; i < m; i++) {
		int a, b, c;
		
		cin >> a >> b >> c;
		vc[a].push_back({b, c});
		vc[b].push_back({a, c});
	}
	
	priority_queue< pair<int, int> > pq;
	pq.push({0, 1});
	
	while(!pq.empty()) {
		int cur_cost = -pq.top().first;
		int cur_idx = pq.top().second;
		
		pq.pop();
		
		if(visited[cur_idx]) {
			continue;
		}
		
		visited[cur_idx] = true;
		res += cur_cost;
		
		for(auto c : vc[cur_idx]) {
			int next_idx = c.first;
			int next_cost = c.second;
			
			if(visited[next_idx]) {
				continue;
			}
			
			pq.push({-next_cost, next_idx});
		}
	}
	
	cout << res;
}