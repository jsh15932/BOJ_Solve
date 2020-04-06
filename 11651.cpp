#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.second < b.second) return true;
	else if(a.second == b.second) {
		if(a.first < b.first) {
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	vector < pair<int, int> > v(n);
	
	for(int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(int i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}
