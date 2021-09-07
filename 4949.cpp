#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
	while(true) {
		getline(cin, s);
		
		if(s.size() == 1 && s[0] == '.') {
			break;
		}
		
		bool chk = true;
		stack<char> st;
		
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '('|| s[i] == '[') {
				st.push(s[i]);
			}
			
			else if(s[i] == ')') {
				if(st.size() > 0 && st.top() == '(') {
					st.pop();
				}
				
				else {
					chk = false;
					
					break;
				}
			}
			
			else if(s[i] == ']') {
				if(st.size() > 0 && st.top() == '[') {
					st.pop();
				}
				
				else {
					chk = false;
					
					break;
				}
			}
		}
		
		if(st.empty() && chk) {
			cout << "yes" << endl;
		}
		
		else {
			cout << "no" << endl;
		}
	}
}