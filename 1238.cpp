#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 987654321

int n, m, x;
int a, b, c;
int d[1001];
int d1[1001], d2[1001];
vector < pair <int, int> > vc[1001];
priority_queue < pair <int, int> > pq;
int ans1, ans2;

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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> x;
	
	for(int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		
		vc[a].push_back(make_pair(b, c));
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			d[j] = INF;
		}
		
		pq.push(make_pair(0, i));
		d[i] = 0;
		
		dijkstra();
		
		d1[i] = d[x];
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			d[j] = INF;
		}
		
		pq.push(make_pair(0, x));
		d[x] = 0;
		
		dijkstra();
		
		d2[i] = d1[i] + d[i];
	}
	
	sort(d2 + 1, d2 + n + 1);
	reverse(d2 + 1, d2 + n + 1);
	
	cout << d2[1];
}
