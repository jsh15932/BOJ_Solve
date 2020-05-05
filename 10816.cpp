#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

map <int, int> cnt;
int n, m, num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> num;
		cnt[num]++;
	}
	
	cin >> m;
	
	for(int i = 0; i < m; i++) {
		cin >> num;
		cout << cnt[num] << ' ';
	}
}
