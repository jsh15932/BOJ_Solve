#include<bits/stdc++.h>
using namespace std;

int n;
int dp[101][101];

void floyd() {
	for(int via = 0; via < n; via++) {
		for(int from = 0; from < n; from++) {
			for(int to = 0; to < n; to++) {
				if(dp[from][via] == 1 && dp[via][to] == 1) {
					dp[from][to] = 1;
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &dp[i][j]);
		}
	}
	
	floyd();
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d ", dp[i][j]);
		}
		
		printf("\n");
	}
}
