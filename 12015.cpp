#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    
    vector<int> vc;
    vc.push_back(0);
    
    int num;
    
    for(int i = 0; i < n; i++) {
        cin >> num;
        
        if(vc.back() < num) {
            vc.push_back(num);
        }
        
        else {
            int idx = lower_bound(vc.begin(), vc.end(), num) - vc.begin();
            vc[idx] = num;
        }
    }
    
    cout << vc.size() - 1 << endl;
}