#include<bits/stdc++.h>
using namespace std;
#define maxN 100001

int n, k;
bool chk[maxN];

int bfs() {
    priority_queue<pair<int, int>, vector< pair<int ,int>>, greater< pair<int, int>>> pq;
    pq.push({ 0, n });
    chk[n] = true;

    while(!pq.empty()) {
        int pq1 = pq.top().first;
        int pq2 = pq.top().second;
        pq.pop();

        if(pq2 == k) {
            return pq1;
        }

        if(pq2 * 2 < maxN && !chk[pq2 * 2]) {
            pq.push({ pq1, pq2 * 2 });
            chk[pq2 * 2] = true;
        }

        if(pq2 + 1 < maxN && !chk[pq2 + 1]) {
            pq.push({ pq1 + 1, pq2 + 1 });
            chk[pq2 + 1] = true;
        }

        if(pq2 - 1 >= 0 && !chk[pq2 - 1]) {
            pq.push({ pq1 + 1, pq2 - 1 });
            chk[pq2 - 1] = true;
        }
    }
}

int main() {
    cin >> n >> k;
    cout << bfs();
}