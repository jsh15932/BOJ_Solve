#include<iostream>
#include<algorithm>
using namespace std;

int n;
int map[101][101];

void floyd() {
	for(int via = 1; via <= n; via++) {
		for(int from = 1; from <= n; from++) {
			for(int to = 1; to <= n; to++) {
				if(map[from][via] && map[via][to]) {
					map[from][to] = 1;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	
	floyd();
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << map[i][j] << ' ';
		}
		
		cout << endl;
	}
}
