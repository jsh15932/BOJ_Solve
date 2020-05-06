#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define max 20010
#define INF 987654321

int v, e, start;
int a, b, c;
int d[max];
vector < pair <int, int> > vc[max];
priority_queue < pair <int, int> > pq;

void Solve() {
	while(!pq.empty()) {
		int pq1 = -pq.top().first;
		int pq2 = pq.top().second;
		
		pq.pop();
		
		for(int i = 0; i < vc[pq2].size(); i++) {
			int vc1 = vc[pq2][i].first;
			int vc2 = vc[pq2][i].second;
			
			if(d[vc1] > pq1 + vc2) {
				d[vc1] = pq1 + vc2;
				pq.push(make_pair(-d[vc1], vc1));
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
	
	for(int i = 1; i <= v; i++) {
		d[i] = INF;
	}
	
	pq.push(make_pair(0, start));
	d[start] = 0;
	
	Solve();
	
	for(int i = 1; i <= v; i++) {
		if(d[i] == INF) {
			cout << "INF" << '\n';
		}
		
		else {
			cout << d[i] << '\n';
		}
	}
}
