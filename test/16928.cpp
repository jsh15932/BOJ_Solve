#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[101];
vector<pair<int, int>> p, q;
int dp[6] = {1, 2, 3, 4, 5, 6};
bool chk[101];

int Move(int num) {
    for(int i = 0; i < p.size(); i++) {
        if(num == p[i].first) {
            return p[i].second;
        }
    }

    for(int i = 0; i < q.size(); i++) {
        if(num == q[i].first) {
            return q[i].second;
        }
    }

    return num;
}

int Solve() {
    queue<pair<int, int>> que;
    que.push({ 1, 0 });

    while(!que.empty()) {
        int cur = que.front().first;
        int cnt = que.front().second;
        chk[cur] = true;
        que.pop();

        if(cur == 100) {
            return cnt;
        }

        for(int i = 0; i < 6; i++) {
            int nextIdx = cur + dp[i];
            int next = Move(nextIdx);

            if(!chk[next] && next <= 100) {
                que.push({ next, cnt + 1 });
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int x, y;

        cin >> x >> y;
        p.push_back({ x, y });
    }

    for(int i = 0; i < m; i++) {
        int u, v;

        cin >> u >> v;
        q.push_back({ u, v });
    }

    cout << Solve() << endl;
}   