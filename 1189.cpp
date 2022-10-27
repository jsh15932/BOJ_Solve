#include<bits/stdc++.h>
using namespace std;

int r, c, k, ans;
char arr[6][6];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool chk[6][6];

int dfs(int x, int y, int d) {
    if(d == k && x == 0 && y == c - 1) {
        ans++;
        return ans;
    }

    for(int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if(nextX >= 0 && nextY >= 0 && nextX < r && nextY < c && !chk[nextX][nextY] && arr[nextX][nextY] != 'T') {
            chk[nextX][nextY] = true;
            dfs(nextX, nextY, d + 1);
            chk[nextX][nextY] = false;
        }
    }

    return ans;
}

int main() {
    cin >> r >> c >> k;

    ans = 0;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    chk[r - 1][0] = true;
    
    cout << dfs(r - 1, 0, 1);
    
}