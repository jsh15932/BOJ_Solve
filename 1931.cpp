#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector < pair <int, int> > vc;

bool cmp(pair <int, int> a, pair <int, int> b) {
	if(a.second < b.second) {
		return true;
	}
	
	else if(a.second > b.second) {
		return false;
	}
	
	if(a.first < b. first) {
		return true;
	}
	
	return false;
}

int main() {
	int t = 0;
	int cnt = 0;
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		int t1, t2;
		
		cin >> t1 >> t2;
		
		vc.push_back(make_pair(t1, t2));
	}
	
	sort(vc.begin(), vc.end(), cmp);
	
	for(int i = 0; i < vc.size(); i++) {
		if(t <= vc[i].first) {
			t = vc[i].second;
			cnt++;
		}
	}
	
	cout << cnt;
}
