#include<bits/stdc++.h>
using namespace std;
#define INF 987654321

long long int n, m;
long int d[501];
vector< pair<int, int> > vc[501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	bool chk = false;
	
	for(int i = 2; i <= n; i++) {
		d[i] = INF;
	}
	
	for(int i = 0; i < m; i++) {
		long long int a, b, c;
		
		cin >> a >> b >> c;
		
		vc[a].push_back({ b, c });
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			vector< pair<int, int> > cur = vc[j];
			
			for(int k = 0; k < cur.size(); k++) {
				if(d[j] != INF && d[cur[k].first] > cur[k].second + d[j]) {
					d[cur[k].first] = cur[k].second + d[j];
					
					if(i == n) {
						chk = true;
					}	
				}
			}
		}
	}
	
	if(chk) {
		cout << -1 << endl;
	}
	
	else {
		for(int i = 2; i <= n; i++) {
			if(d[i] == INF) {
				cout << -1 << endl;
			}
			
			else {
				cout << d[i] << endl;
			}
		}
	}
}