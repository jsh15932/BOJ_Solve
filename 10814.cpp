#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct list {
	int age;
	string name;
};

bool cmp(const list &a, const list &b) {
	return a.age < b.age;
}

int main() {
	int n;
	cin >> n;
	vector <list> v(n);
	
	for(int i = 0; i < n; i++) {
		cin >> v[i].age >> v[i].name;
	}
	
	stable_sort(v.begin(), v.end(), cmp);
	
	for(int i = 0; i < n; i++) {
		cout << v[i].age << ' ' << v[i].name << '\n';
	}
}
