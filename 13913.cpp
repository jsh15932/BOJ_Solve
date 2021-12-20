#include<bits/stdc++.h>
using namespace std;
#define maxN 100000

int n, k;
int d[maxN + 1];
int start[maxN + 1];
bool chk[maxN + 1];
queue<int> que;

void solve(int n, int k) {
	if(n != k) {
		solve(n, start[k]);
	}
	
	cout << k << ' ';
}

int main() {
	cin >> n >> k;
	
	d[n] = 0;
	chk[n] = true;
	que.push(n);
	
	while(!que.empty()) {
		int cur = que.front();
		que.pop();
		
		if(cur - 1 >= 0) {
			if(!chk[cur - 1]) {
				que.push(cur - 1);
				chk[cur - 1] = true;
				d[cur - 1] = d[cur] + 1;
				start[cur - 1] = cur;
			}
		}
		
		if(cur + 1 <= maxN) {
			if(!chk[cur + 1]) {
				que.push(cur + 1);
				chk[cur + 1] = true;
				d[cur + 1] = d[cur] + 1;
				start[cur + 1] = cur;
			}
		}
		
		if(cur * 2 <= maxN) {
			if(!chk[cur * 2]) {
				que.push(cur * 2);
				chk[cur * 2] = true;
				d[cur * 2] = d[cur] + 1;
				start[cur * 2] = cur;
			}
		}
	}
	
	cout << d[k] << endl;
	
	solve(n, k);
}
