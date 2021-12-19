#include<bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	
	cin >> a >> b;
		
	int lenA = a.length();
	int lenB = b.length();
	int min = 1e9;
	
	for(int i = 0; i <= lenB - lenA; i++) {
		int k = 0;
		
		for(int j = 0; j < lenA; j++) {
			a[j] != b[i + j] ? k++ : 0;
		}
		
		if(k < min) {
			min = k;
		}
	}
	
	cout << min;
}