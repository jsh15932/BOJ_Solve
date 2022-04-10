#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, m, b, ans;
int res = INF;
int arr[501][501];

int main() {
    cin >> n >> m >> b;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i <= 256; i++) {
        int x = 0, y = 0;

        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                int h = arr[j][k] - i;

                if(h > 0) {
                    x += h;
                }

                else if(h < 0) {
                    y -= h;
                }
            }
        }

        if(x + b >= y) {
            int t = (x * 2) + y;

            if(res >= t) {
                res = t;
                ans = i;
            }
        }
    }

    cout << res << ' ' << ans << endl; 
}