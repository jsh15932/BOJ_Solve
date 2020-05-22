#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m, k;
int idx, num, ans;
bool chk[51];
bool party[51][51];
bool chk_party[51];
vector <int> vc[51];
queue <int> que;

void bfs() {
	while(!que.empty()) {
		int cur = que.front();
		que.pop();
		
		for(int i = 0; i < vc[cur].size(); i++) {
			if(!chk_party[vc[cur][i]]) {
				chk_party[vc[cur][i]] = true;
				que.push(vc[cur][i]);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	cin >> k;
	
	for(int i = 0; i < k; i++) {
		cin >> idx;
		
		chk[idx]++;
	}
	
	for(int i = 0; i < m; i++) {
		cin >> num;
		
		for(int j = 0; j < num; j++) {
			cin >> idx;
			party[i][idx] = true;
			
			if(chk[idx] && !chk_party[i]) {
				chk_party[i] = true;
				que.push(i);
			}
			
			for(int k = 0; k < i; k++) {
				if(party[k][idx]) {
					vc[k].push_back(i);
					vc[i].push_back(k);
				}
			}
		}
	}
	
	bfs();
	
	for(int i = 0; i < m; i++) {
		if(!chk_party[i]) {
			ans++;
		}
	}
	
	cout << ans;
}
