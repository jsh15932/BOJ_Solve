#include<bits/stdc++.h>
using namespace std;

int tc, n, m;

int main() {
	cin >> tc;
	
	while(tc--) {
		cin >> n >> m;
		
		queue< pair<int, int> > que;
		priority_queue<int> pq;	
		
		for(int i = 0; i < n; i++) {
			int num;
			
			cin >> num;
			
			que.push({ i, num });
			pq.push(num);
		}
		
		int cnt = 0;
		
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
				que.push({ curIdx, curNum });
			}
		}
	}
}