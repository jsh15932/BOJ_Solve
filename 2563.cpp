#include<iostream>
#include<algorithm>
using namespace std;

int n;
int x, y;
int ans;
int d[101][101];

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> y >> x;
		
		for(int i = x + 1; i <= x + 10; i++) {
			for(int j = y + 1; j <= y + 10; j++) {
				d[i][j] = 1;
			}
		}
	}
	
	for(int i = 1; i <= 100; i++) {
		for(int j = 1; j <= 100; j++) {
			if(d[i][j]) {
				ans++;
			}
		}
	}
	
	cout << ans;
}
