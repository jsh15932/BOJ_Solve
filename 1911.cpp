#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
p arr[10001];
int n, l;

bool cmp(const p& p1, const p& p2) {
    if(p1.first == p2.first) {
        return p1.second > p2.second;
    } 

    else {
        return p1.first < p2.first;
    }
}

int main() {
    cin >> n >> l;

    for(int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr + n, cmp);

    int cnt = 0;
    int tmp = 0;
    int end = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i].second - 1 < end) {
            continue;
        }

        if(arr[i].first > end) {
            tmp = (arr[i].second - arr[i].first) / l;

            if((arr[i].second - arr[i].first) % l != 0) {
                tmp++;
            }

            cnt += tmp;
            end = arr[i].first + (l * tmp) - 1;
        }

        else {
            tmp = (arr[i].second - end - 1) / l;

            if((arr[i].second - end - 1) % l != 0) {
                tmp++;
            }

            cnt += tmp;
            end = end + (l * tmp);
        }
    }

    cout << cnt;
}