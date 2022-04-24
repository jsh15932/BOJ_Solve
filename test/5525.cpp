#include<bits/stdc++.h>
using namespace std;

int n, m;
string s;

int main() {
    cin >> n >> m;
    cin >> s;

    int ans = 0;

    for(int i = 0; i < m; i++) {
        int cnt = 0;

        if(s[i] == 'O') {
            continue;
        }

        else {
            while(s[i + 1] == 'O' && s[i + 2] == 'I') {
                cnt++;

                if(cnt == n) {
                    cnt--;
                    ans++;
                }
                i += 2;
            }

            cnt = 0;
        }
    }

    cout << ans << endl;
}