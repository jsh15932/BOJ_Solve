#include<iostream>
#include<algorithm>
using namespace std;

int d[10];
int sum;

int main() {
	for(int i = 0; i < 10; i++) {
		cin >> d[i];
	}
	
	for(int i = 0; i < 10; i++) {
		if(abs(sum + d[i] - 100) <= abs(sum - 100)) {
			sum += d[i];
		}
		
		else {
			break;
		}
	}

	cout << sum;
}
