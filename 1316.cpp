#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int cnt = 0;
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		string s;
		string str;
		int c[26] = {0, };
		
		cin >> s;
		str = s + s[s.size() - 1];
		
		bool chk = true;
		
		for(int j = 0; j < s.size() + 1; j++) {
			if(str[j] != str[j + 1]) {
				c[str[j] - 'a']++;
			}
		}
		
		for(int j = 0; j < 26; j++) {
			if(c[j] > 1) {
				chk = false;
			}
		}
		
		if(chk) {
			cnt++;
		}
	}
	
	cout << cnt << endl;
}