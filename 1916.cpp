#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 987654321

int n, m;
int d[1001];
int a, b, c;
int start, end;
priority_queue < pair <int, int> > pq;
vector < pair <int, int> > vc[1001];

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
	}
	
	for(int i = 1; i <= n; i++) {
		d[i] = INF;
	}
	
	cin >> start >> end;
	
	pq.push(make_pair(0, start));
	d[start] = 0;
	
	dijkstra();
	
	cout << d[end];
}
