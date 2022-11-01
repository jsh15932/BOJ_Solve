#include<bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, m;
int arr[50001];
vector< pair<int, int> > vc[50001];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

int main() {
  cin >> n >> m;

  for(int i = 1; i <= n; i++) {
    arr[i] = INF;
  }

  for(int i = 0; i < m; i++) {
    int x, y, z;
    
    cin >> x >> y >> z;

    vc[x].push_back({ y, z });
    vc[y].push_back({ x, z });
  }

  pq.push({ 0, 1 });
  arr[1] = 0;

  while(!pq.empty()) {
    int pq1 = pq.top().first;
    int pq2 = pq.top().second;
    pq.pop();

    if(arr[pq2] >= pq1) {
      for(int i = 0; i < vc[pq2].size(); i++) {
        int next = vc[pq2][i].first;
        int nextCost = vc[pq2][i].second;
    
        if(arr[next] > nextCost + pq1) {
          arr[next] = nextCost + pq1;
          pq.push({ arr[next], next });
        } 
      }
    }
  }

  cout << arr[n];
}