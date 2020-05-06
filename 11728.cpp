#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector <int> vc;
int num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n + m; i++) {
		cin >> num;
		vc.push_back(num);
	}
	
	sort(vc.begin(), vc.end());
	
	for(int i = 0; i < n + m; i++) {
		cout << vc[i] << ' ';
	}
}
