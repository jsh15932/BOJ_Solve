#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> vc;

        for(int i = 0; i < n; i++) {
            int p, q;
            cin >> p >> q;
            vc.push_back({ p, q });
        }

        sort(vc.begin(), vc.end());
        int ans = 1;
        int tmp = vc[0].second;

        for(int i = 1; i < vc.size(); i++) {
            if(vc[i].second < tmp) {
                ans++;
                tmp = vc[i].second;
                
                if(tmp == 1) {
                    break;
                }
            }
        }

        cout << ans << endl;
    }
}