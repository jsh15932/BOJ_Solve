#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	vector<int> vc;
	
	cin >> n;
	
	while(n--) {
		int num;
		
		cin >> num;
		
		vc.push_back(num);
	}
	
	if(prev_permutation(vc.begin(), vc.end())) {
		for(int i = 0; i < vc.size(); i++) {
			cout << vc[i] << " ";
		}
	}
	
	else {
		cout << -1 << endl;
	}
}