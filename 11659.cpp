#include<bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int arr[n + 1];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while(m--) {
        int x, y;
        int ans = 0;

        cin >> x >> y;

        for(int i = x - 1; i < y; i++) {
            ans += arr[i];
        }

        cout << ans << endl;
    }
}