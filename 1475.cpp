#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	vector<int> vc(10);
	int max = 0, chk = 0;
	
	cin >> s;
	
	for(int i = 0; i < s.size(); i++) {
		vc[s.at(i) - '0']++;
		
		if(s.at(i) - '0' == 6 || s.at(i) - '0' == 9) {
			chk++;
		}
	}
	
	for(int i = 0; i < 10; i++) {
		if(i != 6 && i != 9 && vc[i] > max) {
			max = vc[i];
		}	
	}
	
	if((chk + 1) / 2 > max) {
		max = (chk + 1) / 2;
	}
	
	cout << max << endl;
}