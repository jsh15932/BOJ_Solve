#include<iostream>
#include<algorithm>
using namespace std;

int n, k;
pair < pair < int, int >, pair < int, int > > d[1001];

bool cmp(pair < pair < int, int >, pair < int, int > > a, pair < pair < int, int >, pair < int, int > > b) {
	if(a.first.second > b.first.second) {
		return true;
	}
	
	else if(a.first.second == b.first.second) {
		if(a.second.first > b.second.first) {
			return true;
		}
		
		else if(a.second.first == b.second.first) {
			if(a.second.second > b.second.second) {
				return true;
			}
			
			else if(a.second.second == b.second.second) {
				return a.first.first == k;
			}
		}
	}
	
	return false;
}

int main() {
	cin >> n >> k;
	
	for(int i = 0; i < n; i++) {
		cin >> d[i].first.first >> d[i].first.second >> d[i].second.first >> d[i].second.second;
	}
	
	sort(d, d + n, cmp);
	
	for(int i = 0; i < n; i++) {
		if(d[i].first.first == k) {
			cout << i + 1 << '\n';
			break;
		}
	}
}
