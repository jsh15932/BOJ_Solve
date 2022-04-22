#include<bits/stdc++.h>
using namespace std;

int n;
int arr[101][101];

void floyd() {
    for(int via = 0; via < n; via++) {
        for(int from = 0; from < n; from++) {
            for(int to = 0; to < n; to++) {
                if(arr[from][via] == 1 && arr[via][to] == 1) {
                    arr[from][to] = 1;
                }
            }
        }
    } 
}

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    
    floyd();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << ' ';
        }
        
        cout << endl;
    }
}