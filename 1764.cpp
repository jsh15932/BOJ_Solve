#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector <string> vc;
vector <string> res;
string s;

int main() {
	cin >> n >> m;
	
	vc.resize(n);
	
	for(int i = 0; i < n; i++) {
		cin >> vc[i];
	}
	
	sort(vc.begin(), vc.end());
	
	for(int i = 0; i < m; i++) {
		cin >> s;
		
		if(binary_search(vc.begin(), vc.end(), s)) {
			res.push_back(s);
		}
	}
	
	sort(res.begin(), res.end());
	
	cout << res.size() << '\n';
	
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}
