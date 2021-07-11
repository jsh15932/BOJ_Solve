#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	
	while(tc--) {
		int n = 0, m = 0;
		int cnt = 0;
		
		queue<pair <int, int> > que;
		priority_queue<int> pq;
		
		cin >> n >> m;
		
		for(int j = 0; j < n; j++) {
			int num;
			cin >> num;
			
			que.push({j, num});
			pq.push(num);
		}
		
		while(!que.empty()) {
			int curIdx = que.front().first;
			int curNum = que.front().second;
			que.pop();
			
			if(pq.top() == curNum) {
				pq.pop();
				cnt++;
				
				if(curIdx == m) {
					cout << cnt << endl;
					
					break;
				}
			}
			
			else {
				que.push({curIdx, curNum});
			}
		}
	}
}