#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;

map <int, int> cnt;
int n, m, num;

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &num);
		cnt[num]++;
	}
	
	scanf("%d", &m);
	
	for(int i = 0; i < m; i++) {
		scanf("%d", &num);
		printf("%d ", cnt[num]);
	}
}
