#include<bits/stdc++.h>
using namespace std;

int n, m;
string s[101][101] = {};

string solve(string a, string b) {
	int sum = 0;
	string res;
	
	while(!a.empty() || !b.empty() || sum != 0) {
		if(!a.empty()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		
		if(!b.empty()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		
		res.push_back((sum % 10) + '0');
		sum /= 10;
	}
	
	reverse(res.begin(), res.end());
	
	return res;
}

string comb(int n, int m) {
	if(n == m || m == 0) {
		return "1";
	}
	
	if(s[n][m] != "") {
		return s[n][m];
	}
	
	return s[n][m] = solve(comb(n - 1, m - 1), comb(n - 1, m));
}

int main() {
	cin >> n >> m;
	
	cout << comb(n, m);
}