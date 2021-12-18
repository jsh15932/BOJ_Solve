#include<bits/stdc++.h>
using namespace std;

int n, num;
stack<int> s;

int main() {
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
	
	int sum = 0;
	
	while(!s.empty()) {
		sum += s.top();
		s.pop();
	}
	
	cout << sum << endl;
}