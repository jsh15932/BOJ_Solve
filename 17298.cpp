#include<bits/stdc++.h>
using namespace std;

int n;
stack<int> st, m, ans;

int main() {
	cin >> n;
	
	int arr[n];
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		
		st.push(arr[i]);
	}
	
	m.push(-1);
	
	for(int i = n - 1; i >= 0; i--) {
		while(!st.empty() && (st.size() > i + 1)) {
			if(arr[i] < st.top()) {
				m.push(st.top());
			}
			
			st.pop();
		}
		
		while(!m.empty() && arr[i] >= m.top()) {
			m.pop();
		}
		
		if(!m.empty() && arr[i] < m.top()) {
			ans.push(m.top());
		}
		
		else {
			ans.push(-1);
		}
	}
	
	while(!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
}