#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, num;
vector <int> vc;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> num;
		vc.push_back(num);
	}
	
	sort(vc.begin(), vc.end());
	
	cin >> m;
	
	for(int i = 0; i < m; i++) {
		cin >> num;
		
		if(binary_search(vc.begin(), vc.end(), num)) {
			cout << "1 ";
		}
		
		else {
			cout << "0 ";
		}
	}
}
