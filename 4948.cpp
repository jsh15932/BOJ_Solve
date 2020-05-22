#include<iostream>
#include<algorithm>
using namespace std;

int n;
int d[300001];
bool chk[300001];

int main() {
	cin >> n;
	
	chk[0] = true;
	chk[1] = true;
	
	for(int i = 2; i <= 300000; i++) {
		if(chk[i]) {
			continue;
		}
		
		for(int j = i + i; j <= 300000; j += i) {
			chk[j] = true;
		}
	}
	
	for(int i = 2; i <= 300000; i++) {
		if(!chk[i]) {
			d[i]++;
		}
		
		d[i] += d[i - 1];
	}
	
	while(n) {
		cout << d[n * 2] - d[n] << endl;
		
		cin >> n;
	}
}
