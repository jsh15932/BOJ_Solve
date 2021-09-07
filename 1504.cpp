#include<bits/stdc++.h>
using namespace std;
#define INF 987654321

long long int n, e;
long long int arr[801][801];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> e;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			arr[i][j] = arr[j][i] = INF;
		}
	}
	
	for(int i = 0; i < e; i++) {
		long long int a, b, c;
		
		cin >> a >> b >> c;
		
		arr[a][b] = arr[b][a] = c;
	}
	
	long long int v1, v2;
	
	cin >> v1 >> v2;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) {
				arr[i][j] = arr[j][i] = 0;
			}
		}
	}
	
	for(int via = 1; via <= n; via++) {
		for(int from = 1; from <= n; from++) {
			for(int to = 1; to <= n; to++) {
				if(arr[from][to] > arr[from][via] + arr[via][to]) {
					arr[from][to] = arr[from][via] + arr[via][to];
				}
			}
		}
	}
	
	long long int ans = min(arr[1][v1] + arr[v1][v2] + arr[v2][n], arr[1][v2] + arr[v2][v1] + arr[v1][n]);
	
	if(ans >= INF) {
		cout << -1;
	}
	
	else {
		cout << ans << endl;
	}
}