#include<bits/stdc++.h>
using namespace std;

int l, r, c;
char arr[31][31][31];
int cnt[31][31][31];
int d[31][31][31];
bool chk[31][31][31];
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
queue< pair< int, pair< int, int > > > que;

int main() {
    while(1) {
        cin >> l >> r >> c;

        if(l == 0 && r == 0 && c == 0) {
            break;
        }

        for(int i = 0; i < l; i++) {
            for(int j = 0; j < r; j++) {
                for(int k = 0; k < c; k++) {
                    d[i][j][k] = 0;
                    cnt[i][j][k] = 0;
                    chk[i][j][k] = false;
                }
            }
        }

        bool res = false;

        for(int i = 0; i < l; i++) {
            for(int j = 0; j < r; j++) {
                for(int k = 0; k < c; k++) {
                    char ch;

                    cin >> ch;

                    arr[i][j][k] = ch;

                    if(ch == 'S') {
                        chk[i][j][k] = true;
                        que.push({ i, { j, k }});
                    }

                    else if(ch == '#') {
                        d[i][j][k] = 1;
                    }
                }
            }
        }

        while(!que.empty()) {
            if(res) {
                break;
            }

            int q1 = que.front().first;
            int q2 = que.front().second.first;
            int q3 = que.front().second.second;
            que.pop();

            for(int i = 0; i < 6; i++) {
                if(q1 + dx[i] >= 0 && q2 + dy[i] >= 0 && q3 + dz[i] >= 0 && q1 + dx[i] < l && q2 + dy[i] < r && q3 + dz[i] < c) {
                    if(!chk[q1 + dx[i]][q2 + dy[i]][q3 + dz[i]] && d[q1 + dx[i]][q2 + dy[i]][q3 + dz[i]] == 0) {
                        chk[q1 + dx[i]][q2 + dy[i]][q3 + dz[i]] = true;
                        cnt[q1 + dx[i]][q2 + dy[i]][q3 + dz[i]] = cnt[q1][q2][q3] + 1;

                        if(arr[q1 + dx[i]][q2 + dy[i]][q3 + dz[i]] == 'E') {
                            cout << "Escaped in " << cnt[q1 + dx[i]][q2 + dy[i]][q3 + dz[i]] << " minute(s)." << endl;
                            res = true;

                            break;
                        }
                            
                        else {
                            que.push({ q1 + dx[i], { q2 + dy[i], q3 + dz[i] }});
                        }
                    }
                }
            }
        }

        while(!que.empty()) {
            que.pop();
        }

        if(!res) {
            cout << "Trapped!" << endl;
        }
    }

    return 0;
}