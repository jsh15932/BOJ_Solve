#include<bits/stdc++.h>
using namespace std;

long long int n, m;

int main() {
    scanf("%lld %lld", &n, &m);
    
    long long int maxN = 0;
    long long int tree[n + 1];
    
    for(int i = 0; i < n; i++) {
        scanf("%lld", &tree[i]);
        
        if(tree[i] > maxN) {
            maxN = tree[i];
        }
    }
    
    long long int left = 0;
    long long int right = maxN;
    long long int ans = 0;
    
    while(left <= right) {
        long long int mid = (left + right) / 2;
        long long int total = 0;
        
        for(int i = 0; i < n; i++) {
            if(tree[i] > mid) {
                total += tree[i] - mid;
            }
        }
        
        if(total >= m) {
            ans = mid;
            left = mid + 1;
        }
        
        else {
            right = mid - 1;
        }
    }
    
    printf("%lld", ans);
}