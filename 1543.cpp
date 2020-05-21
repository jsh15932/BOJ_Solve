#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string a, b;
int res;
bool chk;

int main() {
	getline(cin, a);
	getline(cin, b);
	
	if(a.size() < b.size()) {
		cout << 0;
	}
	
	else {
		res = 0;
		
		for(int i = 0; i < a.size() - b.size() + 1; i++) {
			chk = true;
			
			for(int j = 0; j < b.size(); j++) {
				if(a[i + j] != b[j]) {
					chk = false;
					break;
				}
			}
			
			if(chk) {
				res++;
				i += b.size() - 1;
			}
		}
		
		cout << res;
	}
}
