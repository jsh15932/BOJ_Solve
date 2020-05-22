#include<iostream>
#include<algorithm>
using namespace std;

int n;
int d[2];

int main() {
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			cin >> n;
			d[i] += n;
		}
	}
	
	cout << max(d[0], d[1]);
}
