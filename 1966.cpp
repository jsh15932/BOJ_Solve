#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int t, n, m;
int num, ans;
queue < pair < int, int > > que;
priority_queue <int> pq;

int main() {
	cin >> t;
	
	while(t--) {
		ans = 0;
		
		cin >> n >> m;
		
		while(!que.empty() || !pq.empty()) {
			que.pop();
			pq.pop();
		}

		for(int i = 0; i < n; i++) {
			cin >> num;
			que.push(make_pair(num, i));
			pq.push(num);
		}
		
		while(!que.empty()) {
			int q1 = que.front().first;
			int q2 = que.front().second;
			
			que.pop();
			
			if(pq.top() == q1) {
				ans++;
				pq.pop();
				
				if(q2 == m) {
					break;
				}
			}
			
			else {
				que.push(make_pair(q1, q2));
			}
		}
		
		cout << ans << endl;
	}
}
