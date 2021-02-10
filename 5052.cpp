#include<bits/stdc++.h>
using namespace std;

int n, t;

bool chk(string a, string b) {
	int idx = -1;
	int lenA = a.length();
	int lenB = b.length();
	
	if(lenA < lenB) {
		swap(a, b);
		swap(lenA, lenB);
	}
	
	while(++idx < lenB) {
		if(a[idx] != b[idx]) {
			return false;
		}
	}
	
	return true;
}

int main() {
	cin >> t;
	
	while(t--) {
		cin >> n;
		
		vector <string> vc(n);
		
		for(int i = 0; i < n; i++) {
			cin >> vc[i];
		}
		
		sort(vc.begin(), vc.end());
		
		bool ok = true;
		
		for(int i = 0; i < n - 1; i++) {
			if(chk(vc[i], vc[i + 1])) {
				ok = false;
				break;
			}
		}
		
		if(!ok) {
			cout << "NO" << endl;
		}
		
		else {
			cout << "YES" << endl;
		}
	}
}
