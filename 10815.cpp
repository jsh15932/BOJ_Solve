#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, num;
vector <int> vc;

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &num);
		vc.push_back(num);
	}
	
	sort(vc.begin(), vc.end());
	
	scanf("%d", &m);
	
	for(int i = 0; i < m; i++) {
		scanf("%d", &num);
		
		if(binary_search(vc.begin(), vc.end(), num)) {
			printf("1 ");
		}
		
		else {
			printf("0 ");
		}
	}
}
