#include<bits/stdc++.h>
using namespace std;
#define INF 987654321

int v, e, k;
int dp[200001];
priority_queue < pair < int, int > > pq;
vector < pair < int, int > > vc[200001];

void dijkstra() {
	while(!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		
		pq.pop();
		
		for(int i = 0; i < vc[cur].size(); i++) {
			int next = vc[cur][i].first;
			int next_cost = vc[cur][i].second;
			
			if(dp[next] > cost + next_cost) {
				dp[next] = cost + next_cost;
				pq.push(make_pair(-dp[next], next));
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &v, &e, &k);
	
	for(int i = 0; i < e; i++) {
		int a, b, c;
		
		scanf("%d %d %d", &a, &b, &c);
		
		vc[a].push_back(make_pair(b, c));
	}
	
	for(int i = 1; i <= v; i++) {
		dp[i] = INF;
	}
	
	pq.push(make_pair(0, k));
	dp[k] = 0;
	
	dijkstra();
	
	for(int i = 1; i <= v; i++) {
		if(dp[i] == INF) {
			printf("INF\n");
		}
		
		else {
			printf("%d\n", dp[i]);
		}
	}
}
