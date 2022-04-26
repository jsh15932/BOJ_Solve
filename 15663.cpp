#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[9];
bool chk[9];
vector<int> vc;

void Solve(int x, int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << vc[i] << ' ';
        } 
        cout << endl;
        return;
    }

    int tmp = -1;

    for(int i = 1; i <= n; i++) {
        if(chk[i] == false && tmp != arr[i]) {
            vc.push_back(arr[i]);
            tmp = arr[i];
            chk[i] = true;
            Solve(i, cnt + 1);
            chk[i] = false;
            vc.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n + 1);

    Solve(1, 0);
}