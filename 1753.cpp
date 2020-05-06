#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define max 20001
#define INF 987654321

int v, e, start;
int a, b, c;
int d[max];
vector < pair <int, int> > vc[max];
priority_queue < pair <int, int> > pq;

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
	cin >> v >> e >> start;
	
	for(int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		
		vc[a].push_back(make_pair(b, c));
	}
	
	for(int i = 0; i <= v; i++) {
		d[i] = INF;
	}
	
	pq.push(make_pair(0, start));
	d[start] = 0;
	
	dijkstra();
	
	for(int i = 1; i <= v; i++) {
		if(d[i] == INF) {
			cout << "INF" << '\n';
		}
		
		else {
			cout << d[i] << '\n';
		}
	}
}
