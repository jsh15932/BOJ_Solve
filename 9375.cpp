#include<bits/stdc++.h>
using namespace std;

int t, n;

int main() {
    cin >> t;

    while(t--) {
        cin >> n;

        map<string, int> mp;

        while(n--) {
            string x, y;

            cin >> x >> y;

            if(mp.find(y) == mp.end()) {
                mp.insert({ y, 1 });
            }

            else {
                mp[y]++;
            }
        }

        int ans = 1;

        for(auto c : mp) {
            ans *= (c.second + 1);
        }

        ans -= 1;

        cout << ans << endl;
    }
}