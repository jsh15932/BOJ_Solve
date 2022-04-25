#include<bits/stdc++.h>
using namespace std;

int t;
int parent[20001];
int arr[20001];

int Find(int x) {
    if(x == parent[x]) {
        return x;
    }

    return parent[x] = Find(parent[x]);
}

void Union(int x1, int x2) {
    x1 = Find(x1);
    x2 = Find(x2);

    if(x1 != x2) {
        if(arr[x1] < arr[x2]) {
            swap(x1, x2);
        }

        parent[x2] = x1;
        arr[x1] += arr[x2];
        arr[x2] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--) {
        int n;
        
        cin >> n;

        map<string, int> mp;
        int idx = 0;

        for(int i = 0; i < 20001; i++) {
            parent[i] = i;
            arr[i] = 1;
        }

        for(int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;

            if(mp.find(s1) == mp.end()) {
                mp[s1] = idx++;
            }

            if(mp.find(s2) == mp.end()) {
                mp[s2] = idx++;
            }

            int res1 = Find(mp[s1]);
            int res2 = Find(mp[s2]);

            if(res1 == res2) {
                cout << max(arr[res1], arr[res2]) << endl;
            }

            else {
                Union(res1, res2);
                cout << max(arr[res1], arr[res2]) << endl;
            }
        }
    }

    return 0;
}
