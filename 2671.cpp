#include<bits/stdc++.h>
using namespace std;

string s;

bool chk(string s) {
	int i = 0;
	int len = s.length();
	
	while(i < len) {
		if(s[i] == '0') {
			if(i + 1 >= len) {
				return false;
			}
			
			if(s[i + 1] != '1') {
				return false;
			}
			
			i += 2;
		}
		
		else {
			if(i + 3 >= len) {
				return false;
			}
			
			if(!(s[i + 1] == '0' && s[i + 2] == '0')) {
				return false;
			}
			
			i++;
			
			while(i < len && s[i] == '0') {
				i++;
			}
			
			if(i >= len) {
				return false;
			}
			
			i++;
			
			while(i < len && s[i] == '1') {
				if(i + 2 < len && s[i + 1] == '0' && s[i + 2] == '0') {
					break;
				}
				
				i++;
			}
		}
	}
	
	return true;
}


int main() {
	cin >> s;
	
	if(chk(s)) {
		cout << "SUBMARINE";
	}	
	
	else {
		cout << "NOISE";
	}
}
