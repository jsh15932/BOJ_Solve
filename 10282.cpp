#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 987654321

int t, n, d, c;
int a, b, s;
int cnt, time;
int dp[10001];
priority_queue < pair < int, int > > pq;
vector < pair < int, int > > vc[10001];

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
	cin >> t;
	
	while(t--) {
		cin >> n >> d >> c;
		
		for(int i = 1; i <= n; i++) {
			vc[i].clear();
		}
		
		for(int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			
			vc[b].push_back(make_pair(a, s));
		}
		
		for(int i = 1; i <= n; i++) {
			dp[i] = INF;
		}
		
		pq.push(make_pair(0, c));
		dp[c] = 0;
		
		dijkstra();
		
		cnt = 0;
		time = 0;
		
		for(int i = 1; i <= n; i++) {
			if(dp[i] != INF) {
				cnt++;
				
				if(time < dp[i]) {
					time = dp[i];
				}
			}
		}
		
		cout << cnt << ' ' << time << endl;
	}
}
