#include<bits/stdc++.h>
using namespace std;

int n, p, q;
char c[101][101];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
bool chk[101][101];
queue< pair<int, int> > que;

void Solve(int x, int y) {
    char s = c[x][y];

    while(!que.empty()) {
        int q1 = que.front().first;
        int q2 = que.front().second;
        que.pop();

        for(int i = 0; i < 4; i++) {
            if(q1 + dx[i] >= 0 && q2 + dy[i] >= 0 && q1 + dx[i] < n && q2 + dy[i] < n) {
                if(c[q1 + dx[i]][q2 + dy[i]] == s && !chk[q1 + dx[i]][q2 + dy[i]]) {
                    chk[q1 + dx[i]][q2 + dy[i]] = true;
                    que.push({ q1 + dx[i], q2 + dy[i] });
                }
            }
        }
    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for(int j = 0; j < str.size(); j++) {
            c[i][j] = str[j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!chk[i][j]) {
                que.push({ i, j });
                chk[i][j] = true;
                Solve(i, j);
                p++;
            }
        }
    }

    memset(chk, false, sizeof(chk));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(c[i][j] == 'G') {
                c[i][j] = 'R';
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!chk[i][j]) {
                que.push({ i, j });
                chk[i][j] = true;
                Solve(i, j);
                q++;
            }
        }
    }

    cout << p << " " << q << endl;
}