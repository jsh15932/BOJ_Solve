#include<bits/stdc++.h>
using namespace std;

int n;

bool chk(string a, string b) {
	if(a.length() < b.length()) {
		return true;
	}
	
	else if(a.length() > b.length()) {
		return false;
	}
	
	else {
		return a < b;
	}
}

int main() {
	cin >> n;
	
	string s[n];
	
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	
	sort(s, s + n, chk);
	
	for(int i = 0; i < n; i++) {
		if(i > 0 && s[i - 1] == s[i]) {
			continue;
		}
		
		else {
			cout << s[i] << endl;
		}
	}
}
