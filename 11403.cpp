#include<iostream>
#include<algorithm>
using namespace std;

int n;
int d[100][100];

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> d[i][j];
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(d[j][i] && d[i][k]) {
					d[j][k] = 1;
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << d[i][j] << ' ';
		}
		
		cout << '\n';
	}
}
