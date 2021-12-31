#include<bits/stdc++.h>
using namespace std;

int k;
stack<int> st;

int main() {
	cin >> k;
	
	while(k--) {
		int num;
		
		cin >> num;
		
		if(num != 0) {
			st.push(num);	
		}
		
		else {
			st.pop();
		}
	}
	
	int cnt = 0;
	
	while(!st.empty()) {
		cnt += st.top();
		st.pop();
	}
	
	cout << cnt << endl;
}
