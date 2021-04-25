#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
	while(1) {
		getline(cin, s);
		
		if(s.size() == 1 && s[0] == '.') {
			break;
		}
		
		bool chk_line = false;
		stack <char> chk;
		
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == '(' || s[i] == '[') {
				chk.push(s[i]);
			}
			
			else if(s[i] == ')') {
				if(chk.size() > 0 && chk.top() == '(') {
					chk.pop();
				}
				
				else {
					chk_line = true;
					
					break;
				}
			}
			
			else if(s[i] == ']') {
				if(chk.size() > 0 && chk.top() == '[') {
					chk.pop();
				}
				
				else {
					chk_line = true;
					
					break;
				}
			}
		}
		
		if(chk.empty() && !chk_line) {
			cout << "yes" << endl;
		}
		
		else {
			cout << "no" << endl;
		}
	}
}