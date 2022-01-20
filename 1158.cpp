#include<bits/stdc++.h>
using namespace std;

int n, k;
queue<int> que;

int main() {
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++) {
		que.push(i);
	}
	
	cout << "<";
	
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < k - 1; j++) {
			que.push(que.front());
			que.pop();
		}
		
		cout << que.front() << "," << ' ';
		que.pop();
	}
	
	cout << que.front() << ">";
}
