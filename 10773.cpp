#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, num;
	int sum = 0;
	stack<int> s;
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> num;
		
		if(num != 0) {
			s.push(num);
		}
		
		else {
			s.pop();
		}
	}
	
	while(!s.empty()) {
		sum += s.top();
		s.pop();
	}
	
	cout << sum << endl;
}