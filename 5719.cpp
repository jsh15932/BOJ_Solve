#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 987654321
#define max 501

int n, m;
int x, y;
int a, b, c;
vector < pair <int, int> > vc[max];
vector < pair <int, int> > t[max];
bool visited[max][max];

vector <int> dijkstra(int start, int vertex) {
	vector <int> d(vertex, INF);
	d[start] = 0;
	
	priority_queue < pair <int, int> > pq;
	pq.push(make_pair(0, start));
	
	while(!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		
		pq.pop();
		
		if(d[cur] < cost) {
			continue;
		}
		
		for(int i = 0; i < vc[cur].size(); i++) {
			int next = vc[cur][i].first;
			int next_cost = vc[cur][i].second;
			
			if(next_cost == -1) {
				continue;
			}
			
			if(d[next] > cost + next_cost) {
				d[next] = next_cost + cost;
				pq.push(make_pair(-d[next], next));
				
				t[next].clear();
				t[next].push_back(make_pair(cur, cost + next_cost));
			}
			
			else if(d[next] == cost + next_cost) {
				t[next].push_back(make_pair(cur, cost + next_cost));
			}
		}
	}
	
	return d;
}

void bfs(int end) {
	queue <int> q;
	
	q.push(end);
	
	while(!q.empty()) {
		int cur = q.front();
		
		q.pop();
		
		for(int i = 0; i < t[cur].size(); i++) {
			int next = t[cur][i].first;
			
			if(visited[cur][next]) {
				continue;
			}
			
			for(int j = 0; j < vc[next].size(); j++) {
				if(vc[next][j].first == cur) {
					vc[next][j].second = -1;
				}
			}
			
			q.push(next);
		}
	}
}

int main() {
	while(1) {
		memset(visited, false, sizeof(visited));
		memset(t, 0, sizeof(t));
		
		for(int i = 0; i < max; i++) {
			vc[i].clear();
		}
		
		cin >> n >> m;
		
		if(n == 0 && m == 0) {
			break;
		}
		
		cin >> x >> y;
		
		for(int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			
			vc[a].push_back(make_pair(b, c));
		}
		
		dijkstra(x, n);
		
		bfs(y);
		
		vector <int> result = dijkstra(x, n);
		
		if(result[y] == INF) {
			cout << "-1" << endl;
		}
		
		else {
			cout << result[y] << endl;
		}
	}
}
