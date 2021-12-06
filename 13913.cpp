#include<bits/stdc++.h>
using namespace std;
#define INF 200000

int n, k;
bool chk[INF + 1];
int d[INF + 1];
int start[INF + 1];

void print(int n, int k) {
	if(n != k) {
		print(n, start[k]);
	}
	
	cout << k << " ";
}

int main() {
	cin >> n >> k;
	
	chk[n] = true;
	d[n] = 0;
	
	queue<int> que;
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
		
		if(cur + 1 < INF) {
			if(!chk[cur + 1]) {
				que.push(cur + 1);
				chk[cur + 1] = true;
				d[cur + 1] = d[cur] + 1;
				start[cur + 1] = cur;
			}
		}
		
		if(cur * 2 < INF) {
			if(!chk[cur * 2]) {
				que.push(cur * 2);
				chk[cur * 2] = true;
				d[cur * 2] = d[cur] + 1;
				start[cur * 2] = cur;
			}
		}
	}
	
	cout << d[k] << endl;
	
	print(n, k);
}