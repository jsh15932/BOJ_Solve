#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	queue <int> q;
	int n, k;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++) {
		q.push(i);
	}
	
	cout << "<";
	
	for(int i = 0; i < n - 1; i++) {
		for(int j = 0; j < k - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		
		cout << q.front() << "," << ' ';
		q.pop();
	}
	
	cout << q.front() << ">";
}
