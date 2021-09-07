#include<bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	scanf("%d", &n);
	
	vector<int> num(n);
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	
	sort(num.begin(), num.end());
	
	scanf("%d", &m);
	
	vector<int> vc(m);
	
	for(int i = 0; i < m; i++) {
		scanf("%d", &vc[i]);
	}
	
	for(int i = 0; i < m; i++) {
		int left = 0;
		int right = n - 1;
		int ans = 0;
		
		while(left <= right) {
			int mid = (left + right) / 2;
			
			if(vc[i] < num[mid]) {
				right = mid - 1;
			}
			
			else if(vc[i] > num[mid]) {
				left = mid + 1;
			}
			
			else {
				ans = 1;
				
				break;
			}
		}
		
		printf("%d\n", ans);
	}
}