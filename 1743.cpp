#include<bits/stdc++.h>
using namespace std;

int n, m, k, cnt;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int arr[101][101];
bool chk[101][101];

void dfs(int x, int y) {
    cnt++;    
    
    for(int i = 0; i < 4; i++) {
        if(arr[x + dx[i]][y + dy[i]] == 1 && !chk[x + dx[i]][y + dy[i]]) {
            chk[x + dx[i]][y + dy[i]] = true;
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    
    int ans = 0;
    
    for(int i = 0; i < k; i++) {
        int x, y;
        
        cin >> x >> y;
        
        arr[x][y] = 1;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(arr[i][j] == 1 && !chk[i][j]) {
                chk[i][j] = true;
                dfs(i, j);
                
                if(cnt > ans) {
                    ans = cnt;
                }
                
                cnt = 0;
            }
        }
    }
    
    cout << ans;
}