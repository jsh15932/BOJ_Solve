#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[101][101];

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		int a, b, c;
		
		cin >> a >> b >> c;
		
		if(arr[a][b]) {
			arr[a][b] = min(c, arr[a][b]);
		}
		
		else {
			arr[a][b] = c;
		}
	}
	
	for(int via = 1; via <= n; via++) {
		for(int from = 1; from <= n; from++) {
			for(int to = 1; to <= n; to++) {
				if(from == to || arr[from][via] == 0 || arr[via][to] == 0) {
					continue;
				}
				
				if(arr[from][to] == 0 || arr[from][via] + arr[via][to] < arr[from][to]) {
					arr[from][to] = arr[from][via] + arr[via][to];
				}
			}
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << arr[i][j] << ' ';
		}
		
		cout << endl;
	}
}