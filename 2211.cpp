#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 987654321

int n, m;
int a, b, c;
int d[1001];
int parent[1001];
priority_queue < pair < int, int > > pq;
vector < pair < int, int > > vc[1001];

void dijkstra() {
	while(!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		
		pq.pop();
		
		for(int i = 0; i < vc[cur].size(); i++) {
			int next = vc[cur][i].first;
			int next_cost = vc[cur][i].second;
			
			if(d[next] > cost + next_cost) {
				d[next] = cost + next_cost;
				parent[next] = cur;
				pq.push(make_pair(-d[next], next));
			}
		}
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		
		vc[a].push_back(make_pair(b, c));
		vc[b].push_back(make_pair(a, c));
	}
	
	for(int i = 1; i <= n; i++) {
		d[i] = INF;
	}
	
	pq.push(make_pair(0, 1));
	d[1] = 0;
	
	dijkstra();
	
	cout << n - 1 << '\n';
	
	for(int i = 2; i <= n; i++) {
		cout << parent[i] << ' ' << i << endl;
	}
}
