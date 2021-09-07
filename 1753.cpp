#include<bits/stdc++.h>
using namespace std;
#define INF 987654321

int v, e, k;
int arr[20001];
priority_queue< pair<int, int> > pq;
vector< pair <int, int> > vc[20001];

void dijkstra() {
	while(!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		
		pq.pop();
		
		for(int i = 0; i < vc[cur].size(); i++) {
			int next = vc[cur][i].first;
			int next_cost = vc[cur][i].second;
			
			if(arr[next] > cost + next_cost) {
				arr[next] = cost + next_cost;
				pq.push({ -arr[next], next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> v >> e >> k;
	
	for(int i = 0; i < e; i++) {
		int a, b, c;
		
		cin >> a >> b >> c;
		
		vc[a].push_back({ b, c });
	}
	
	for(int i = 1; i <= v; i++) {
		arr[i] = INF;
	}
	
	pq.push({ 0, k });
	arr[k] = 0;
	
	dijkstra();
	
	for(int i = 1; i <= v; i++) {
		if(arr[i] == INF) {
			cout << "INF" << endl;
		}
		
		else {
			cout << arr[i] << endl;
		}
	}
}