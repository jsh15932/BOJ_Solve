#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct list {
	string name;
	int kr;
	int en;
	int ma;
};

bool cmp(const list &a, const list &b) {
	if(a.kr == b.kr && a.en == b.en && a.ma == b.ma) {
		return a.name < b.name;
	}
	
	else if(a.kr == b.kr && a.en == b.en) {
		return a.ma > b.ma;
	}
	
	else if(a.kr == b.kr) {
		return a.en < b.en;
	}
	
	return a.kr > b.kr;
}

int main() {
	int n;
	cin >> n;
	
	vector <list> v(n);
	
	for(int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].kr >> v[i].en >> v[i].ma;
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(int i = 0; i < n; i++) {
		cout << v[i].name << '\n';
	}
}
