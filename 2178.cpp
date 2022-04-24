#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
queue< pair<int, int> > que;
bool chk[101][101];
int cnt[101][101];

void Solve() {
    while(!que.empty()) {
        int q1 = que.front().first;
        int q2 = que.front().second;

        que.pop();

        for(int i = 0; i < 4; i++) {
            if(q1 + dx[i] >= 0 && q2 + dy[i] >= 0 && q1 + dx[i] < n && q2 + dy[i] < m) {
                if(arr[q1 + dx[i]][q2 + dy[i]] == 1 && !chk[q1 + dx[i]][q2 + dy[i]]) {
                    chk[q1 + dx[i]][q2 + dy[i]] = true;
                    que.push({ q1 + dx[i], q2 + dy[i] });
                    cnt[q1 + dx[i]][q2 + dy[i]] = cnt[q1][q2] + 1;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }

    cnt[0][0] = 1;
    que.push({ 0, 0 });
    Solve();

    cout << cnt[n - 1][m - 1] << endl;
}
