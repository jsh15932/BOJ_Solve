#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[100001];
int sum = 0;

int main() {
  cin >> n >> m;

  int left = 0, right = 0;
  
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
    left = max(left, arr[i]);
  }

  right = sum;

  while(left <= right) {
    int cnt = 0;
    int tmp = 0;
    int mid = (left + right) / 2;

    for(int i = 0; i < n; i++) {
      if(tmp + arr[i] > mid) {
        tmp = 0;
        cnt += 1;
      }
      tmp += arr[i];
    }

    if(tmp != 0) {
      cnt += 1;
    }

    if(cnt <= m) {
      right = mid - 1;
    }

    else {
      left = mid + 1;
    }
  }

  cout << left;
}