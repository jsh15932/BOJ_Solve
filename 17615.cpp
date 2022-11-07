#include<bits/stdc++.h>
using namespace std;
#define maxN 500001

int n, cntR, cntB;
string s;

int main() {
    cin >> n >> s;

    for(auto i:s) {
        if(i == 'R') {
            cntR++;
        }

        else {
            cntB++;
        }
    }

    int minN = maxN;
    int cnt = 0;
    int idx = 0;

    while(s[idx++] == 'R') {
        cnt++;
    }

    minN = min(minN, cntR - cnt);
    idx = n - 1, cnt =0;

    while(s[idx--] == 'R') {
        cnt++;
    }


    minN = min(minN, cntR - cnt);
    cnt = 0, idx = 0;

    while(s[idx++] == 'B') {
        cnt++;
    }

    minN = min(minN, cntB - cnt);
    idx = n - 1, cnt =0;

    while(s[idx--] == 'B') {
        cnt++;
    }

    minN = min(minN, cntB - cnt);

    cout << minN << endl;
}