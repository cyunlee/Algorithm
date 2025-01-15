#include <bits/stdc++.h>
using namespace std;

int vis[100002];
int dist[100002];

bool OOB(int x) {
  return x < 0 || x > 100000;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  //우선순위 큐 : 거리, 위치
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  dist[n] = 0;
  vis[n] = 1;
  pq.push({0, n});

  while(!pq.empty()){
    int curDist = pq.top().first;
    int cur = pq.top().second;
    pq.pop();

    if(cur==k) {
      cout << curDist;
      return 0;
    }

    for(int x : {cur-1, cur+1, cur*2}){
      if(OOB(x)) continue;
      if(vis[x]==0 || curDist + 1 < dist[x]) {
        vis[x] = 1;
        dist[x] = curDist + (x==cur*2? 0 : 1);
        pq.push({dist[x], x});
      }
    }
  }
}