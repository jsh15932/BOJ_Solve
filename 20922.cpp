#include<bits/stdc++.h>
using namespace std;

int n, k, ans;
int arr[100001];
deque<int> dq;

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int num;

        cin >> num;

        arr[num]++;

        if(dq.empty()) {
            dq.push_back(num);
        }

        else {
            if(arr[num] <= k) {
                dq.push_back(num);
            }

            else {
                int p = -1;

                while(!dq.empty() && p != num) {
                    p = dq.front();
                    dq.pop_front();
                    arr[p] -= 1;
                }

                dq.push_back(num);
            }
        }

        int size = dq.size();
        ans = max(ans, size);
    }

    cout << ans;
}