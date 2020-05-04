#include<iostream>
#include<algorithm>
using namespace std;

int d[11] = {1, 2, 4, };
int tc, num;

int main() {
	cin >> tc;
	
	while(tc--) {
		cin >> num;
		
		for(int i = 3; i < num; i++) {
			d[i] = d[i - 1]  + d[i - 2] + d[i - 3];
		}
		
		cout << d[num - 1] << endl;
	}
}
