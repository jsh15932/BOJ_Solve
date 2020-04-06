#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string str(string s) {
	int cnt = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(') {
			cnt += 1;
		}
		else {
			cnt -= 1;
		}
		if(cnt < 0) {
			return "NO";
		}
	}
	
	if(cnt == 0) {
		return "YES";
	}
	
	else {
		return "NO";
	}
}

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		string s;
		cin >> s;
		cout << str(s) << endl;
	}
}
