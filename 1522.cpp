#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin >> s;

    int cnt = 0;
    int ans = 1e9;
    int len = s.length();
    int res = 0;

    for(int i = 0; i < len; i++) {
        if(s[i] == 'b') {
            cnt++;
        }
    }

    for(int i = 0; i < s.length(); i++) {
        res = 0;

        for(int j = i; j < i + cnt; j++) {
            if(s[(j + 1) % len] == 'a') {
                res++;
            }
        }

        ans = min(ans, res);
    }

    cout << ans;
}