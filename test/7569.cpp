#include<bits/stdc++.h>
using namespace std;

int n, m, h;
int arr[101][101][101];
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
queue<pair<pair<int, int>, int>> que;

void bfs() {
    while(!que.empty()) {
        int q1 = que.front().first.first;
        int q2 = que.front().first.second;
        int q3 = que.front().second;
        que.pop();

        for(int i = 0; i < 6; i++) {
            if(q1 + dx[i] >= 0 && q2 + dy[i] >= 0 && q3 + dz[i] >= 0 && q1 + dx[i] < h && q2 + dy[i] < n && q3 + dz[i] < m) {
                if(arr[q1 + dx[i]][q2 + dy[i]][q3 + dz[i]] == 0) {
                    arr[q1 + dx[i]][q2 + dy[i]][q3 + dz[i]] = arr[q1][q2][q3] + 1;
                    que.push({ { q1 + dx[i], q2 + dy[i] }, q3 + dz[i] });
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> h;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> arr[i][j][k];

                if(arr[i][j][k] == 1) { 
                    que.push({ { i, j }, k });
                }
            }
        }
    }
    
    bfs();

    int ans = 0;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(arr[i][j][k] == 0) {
                    cout << "-1" << endl;
                    return 0;
                }

                if(arr[i][j][k] > ans) {
                    ans = arr[i][j][k];
                }
            }
        }
    }

    cout << ans - 1 << endl;
}