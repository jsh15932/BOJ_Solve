#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m;
int d[1001][1001];
string s;

void solve(string &s, char c, int cnt) {
	for(int i = 0; i < cnt; i++) {
		s += c;
	}
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> d[i][j];
		}
	}
	
	if(n % 2 == 1) {
		for(int i = 0; i < n; i++) {
			if(i % 2 == 0) {
				solve(s, 'R', m - 1);
				
				if(i != n - 1) {
					solve(s, 'D', 1);
				}
			}
			
			else {
				solve(s, 'L', m - 1);
				solve(s, 'D', 1);
			}
		}
	}
	
	else if(m % 2 == 1) {
		for(int i = 0; i < m; i++) {
			if(i % 2 == 0) {
				solve(s, 'D', n - 1);
				
				if(i != m - 1) {
					solve(s, 'R', 1);
				}
			}
			
			else {
				solve(s, 'U', n - 1);
				solve(s, 'R', 1);
			}
		}
	}
	
	else {
		int x = 0;
		int y = 1;
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if((i + j) % 2 == 1) {
					if(d[x][y] > d[i][j]) {
						x = i;
						y = j;
					}
				}
			}
		}
		
		int x1 = 0;
		int y1 = 0;
		int x2 = n - 1;
		int y2 = m - 1;
		string s2;
		
		while(x2 - x1 > 1) {
			if(x1 / 2 < x / 2) {
				solve(s, 'R', m - 1);
				solve(s, 'D', 1);
				solve(s, 'L', m - 1);
				solve(s, 'D', 1);
				
				x1 += 2;
			}
			
			if(x / 2 < x2 / 2) {
				solve(s2, 'R', m - 1);
				solve(s2, 'D', 1);
				solve(s2, 'L', m - 1);
				solve(s2, 'D', 1);
				
				x2 -= 2;
			}
		}
		
		while(y2 - y1 > 1) {
			if(y1 / 2 < y / 2) {
				solve(s, 'D', 1);
				solve(s, 'R', 1);
				solve(s, 'U', 1);
				solve(s, 'R', 1);
				
				y1 += 2;
			}
			
			if(y / 2 < y2 / 2) {
				solve(s2, 'D', 1);
				solve(s2, 'R', 1);
				solve(s2, 'U', 1);
				solve(s2, 'R', 1);
				
				y2 -= 2;
			}
		}
		
		if(y == y1) {
			solve(s, 'R', 1);
			solve(s, 'D', 1);
		}
		
		else {
			solve(s, 'D', 1);
			solve(s, 'R', 1);
		}
		
		reverse(s2.begin(), s2.end());
		
		s += s2;
	}
		
	cout << s;
}
