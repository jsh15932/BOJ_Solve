#include<bits/stdc++.h>
using namespace std;

int n;
struct C {
    int s;
    int t;
};

priority_queue< int, vector<int>, greater<int> > pq;

bool cmp(C a, C b) {
    if(a.s == b.s) {
        return a.t < b.t;
    }

    return a.s < b.s;
}

C arr[200001];

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i].s >> arr[i].t;
    }

    sort(arr, arr + n, cmp);

    pq.push(arr[0].t);

    for(int i = 1; i < n; i++) {
        int s = arr[i].s;
        int t = arr[i].t;
        int cur = pq.top();

        if(s < cur) {
            pq.push(t);
        }

        else {
            pq.pop();
            pq.push(t);
        }
    }

    cout << pq.size();    
}