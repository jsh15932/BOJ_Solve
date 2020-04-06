#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	for(int i = 'a'; i <= 'z'; i++) {
		cout << count(s.begin(), s.end(), i) << ' ';
	}
}
