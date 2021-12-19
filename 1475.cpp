#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> vc(10);

int main() {
	cin >> s;
	
	int cnt = 0;
	
	for(int i = 0; i < s.size(); i++) {
		vc[s.at(i) - '0']++;
		
		if(s.at(i) - '0' == 6 || s.at(i) - '0' == 9) {
			cnt++;
		}
	}
	
	int max = 0;
	
	for(int i = 0; i < 10; i++) {
		if(i != 6 && i != 9 && vc[i] > max) {
			max = vc[i];
		}
	}
	
	if((cnt + 1) / 2 > max) {
		max = (cnt + 1) / 2;
	}
	
	cout << max;
}