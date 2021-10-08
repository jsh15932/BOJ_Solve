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
	
	while(!que.empty()) {
		for(int i = 0; i < k - 1; i++) {
			int tmp = que.front();
			que.pop();
			que.push(tmp);
		} 
		
		if(que.size() == 1) {
			cout << que.front() << ">";
		}
		
		else {
			cout << que.front() << ", ";
		}
		
		que.pop();
	}
}