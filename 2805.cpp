#include<cstdio>
#include<algorithm>
using namespace std;

long long int d[1000001];
int n;
long long int m;

int main() {
	scanf("%d", &n);
	scanf("%lld", &m);
	
	long long int max = 0;
	
	for(int i = 0; i < n; i++) {
		scanf("%lld", &d[i]);
		
		if(max < d[i]) {
			max = d[i];
		}
	}
	
	long long int left = 0;
	long long int right = max;
	long long int result = 0;
	
	while(left <= right) {
		long long int mid = (left + right) / 2;
		long long int total = 0;
		
		for(int i = 0; i < n; i++) {
			if(d[i] > mid) {
				total += d[i] - mid;
			}
		}

		if(total >= m) {
			result = mid;
			left = mid + 1;
		}
		
		else {
			right = mid - 1;
		}
	}
	
	printf("%lld", result);
}
