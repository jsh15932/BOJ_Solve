#include<bits/stdc++.h>
using namespace std;

map<char, int> mp;
string s;

bool chk1() {
    bool chk = false;

    for(int i = 0; i < s.size(); i++) {
        char c = s[i];

        if(mp[c] == 1) {
            chk = true;
        }
    }

    return chk;
}

bool chk2() {
    int cnt1 = 0, cnt2 = 0;

    for(int i = 0; i < s.size(); i++) {
        char c = s[i];

        if(mp[c] == 1) {
            cnt1++;
            cnt2 = 0;
        } 

        else {
            cnt1 = 0;
            cnt2++;
        }

        if(cnt1 == 3 || cnt2 == 3) {
            return false;
        }
    }

    return true;
}

bool chk3() {
    char ch = s[0];

    for(int i = 1; i < s.size(); i++) {
        char c = s[i];

        if(c == ch && c != 'e' && c != 'o') {
            return false;
        }

        ch = c; 
    }

    return true;
}

string solve() {
    bool chk = chk1() && chk2() && chk3();
    
    if(chk) {
        return "acceptable.\n";
    }

    return "not acceptable.\n";
}

int main() {
    mp['a'] = 1, mp['e'] = 1, mp['i'] = 1, mp['o'] = 1, mp['u'] = 1;

    while(true) {
        cin >> s;

        if(s == "end") {
            break;
        }

        cout << "<" << s << ">" << " is " << solve();
    }
}