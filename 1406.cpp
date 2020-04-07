#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int n;
	string s;
	
	cin >> s;
	cin >> n;
	
	stack<char> s1, s2;
	
	for(auto &x:s) {
		s1.push(x);
	}
	
	while(n--) {
		char c;
		cin >> c;
		
		if(c == 'L') {
			if(!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		
		else if(c == 'D') {
			if(!s2.empty()) {
				s1.push(s2.top());
				s2.pop();
			}
		}
		
		else if(c == 'B') {
			if(!s1.empty()) {
				s1.pop();
			}
		}
		
		else if(c == 'P') {
			char x;
			cin >> x;
			s1.push(x);
		}
	}
	
	while(!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}
	
	while(!s2.empty()) {
		cout << s2.top();
		s2.pop();
	}
}
