#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t; //TC
  for(int i=0; i<t; i++){
    int l;
    cin >> l;

    int cx, cy;
    cin >> cx >> cy;

    int ox, oy;
    cin >> ox >> oy;

    queue<pair<int, int>> Q;

    int dist[302][302];

    for(int i=0; i<302; i++){
      for(int j=0; j<302; j++){
        dist[i][j] = -1;
      }
    }

    dist[cx][cy] = 0;
    Q.push({cx, cy});

    while(dist[ox][oy]==-1){
      pair<int, int> cur = Q.front(); Q.pop();

      for(int dir=0; dir<8; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];

        if(nx<0 || nx>=l || ny<0 || ny>=l) continue;
        if(dist[nx][ny]>=0) continue;

        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        Q.push({nx, ny});
      }
    }

    cout << dist[ox][oy] << '\n';
  }
}