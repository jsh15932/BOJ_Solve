#include<bits/stdc++.h>
using namespace std;

string s1, s2;

int main() {
    cin >> s1 >> s2;
    
    stack<char> st;
    
    for(int i = 0; i < s1.size(); i++) {
        st.push(s1[i]);
        
        if(s1[i] == s2[s2.size() - 1] && st.size() >= s2.size()) {
            string res;
            
            for(int j = 0; j < s2.size(); j++) {
                res += st.top();
                st.pop();
            }
            
            reverse(res.begin(), res.end());
            
            bool chk = true;
            
            for(int j = 0; j < res.size(); j++) {
                if(res[j] != s2[j]) {
                    chk = false;
                    break;
                }
            }
            
            if(!chk) {
                for(int j = 0; j < res.size(); j++) {
                    st.push(res[j]);
                }
            }
        }
    }
    
    string ans;
    
    if(st.empty()) {
        cout << "FRULA" << endl;
        return 0;
    }
    
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    
    reverse(ans.begin(), ans.end());
    
    cout << ans << endl;
}