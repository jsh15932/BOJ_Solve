#include<bits/stdc++.h>
using namespace std;

string str;
stack<char> s;

int main() {
	bool chk = false;
	string ans;
	
	getline(cin, str);
	
	for(int i = 0; i < str.size(); i++) {
		if(str[i] != '<') {
			s.push(str[i]);
		}
		
		if(str[i] == '<') {
			while(!s.empty()) {
				ans += s.top();
				s.pop();
			}
			
			s.push(str[i]);
			chk = true;
		}
		
		else if(str[i] == '>') {
			string tmp;
			
			while(!s.empty()) {
				tmp += s.top();
				s.pop();
			}
			
			if(chk) {
				chk = false;
				reverse(tmp.begin(), tmp.end());
				ans += tmp;
			}
		}
		
		else if(str[i] == ' ' || i == str.size() - 1) {
			if(!chk) {
				string tmp;
				int k = 0;
				
				while(!s.empty()) {
					if(s.top() != ' ') {
						tmp += s.top();
					}
					
					else {
						k = 1;
					}
					
					s.pop();
				}
				
				ans += tmp;
				
				if(k) {
					ans += ' ';
				}
			}
		}
	}
	
	cout << ans << endl;
}