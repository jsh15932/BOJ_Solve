#include<iostream>
#include<algorithm>
using namespace std;

long long int n;
int l;
int a, b;

int main() {
	scanf("%lld %d", &n, &l);
	
	if(n % 2 == 0 && l == 2) {
		l = 3;
	}
	
	for(int i = l; i <= 100; i++) {
		a = n / i;
		
		if(i % 2 == 0) {
			a = n / i;
			
			if(n % i != i / 2) {
				continue;
			}
			
			b = a - ((i - 1) / 2);
		}
		
		else {
			a = n / i;
			
			if(n % i != 0) {
				continue;
			}
			
			b = a - (i / 2);
		}
		
		if(b >= 0) {
			for(int j = 0; j < i; j++) {
				printf("%d ", j + b);
			}
			
			return 0;
		}
		
		else {
			break;
		}
	}

	printf("-1");
}
