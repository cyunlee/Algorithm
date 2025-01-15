#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[101][101];
int vis[101][101];
int dist[101][101];
int n, cnt=0;
queue<pair<int, int>> Q;

bool OOB(int x, int y){
  return x<0 || x>=n || y<0 || y>=n;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> board[i][j];
    }
  }

  //섬에 번호 매기기
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(board[i][j]==0 || vis[i][j]==1) continue;

      cnt++;
      board[i][j] = cnt;
      vis[i][j] = 1;
      Q.push({i, j});

      while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for(int dir=0; dir<4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if(OOB(nx, ny)) continue;
          if(board[nx][ny]==0 || vis[nx][ny]==1) continue;
          vis[nx][ny] = 1;
          board[nx][ny] = cnt;
          Q.push({nx, ny});
        }
      }
    }
  }

  int ans = INT_MAX;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(board[i][j]!=0){
        //fill(&dist[0][0], &dist[n][n], -1);
        memset(dist, -1, sizeof(dist));
        dist[i][j]=0;
        Q.push({i, j});
      }
      int landNumber = board[i][j];

      while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();

        for(int dir=0; dir<4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if(OOB(nx, ny)) continue;
          if(dist[nx][ny]>=0||board[nx][ny]==landNumber) continue;
          if(board[nx][ny]!=0 && board[nx][ny]!=landNumber){
            ans = min(ans, dist[cur.X][cur.Y]);
            while(!Q.empty()) Q.pop(); //BFS 종료
            break;
          }

          dist[nx][ny] = dist[cur.X][cur.Y] + 1; //바다 dist 값 갱신
          Q.push({nx, ny});
        }
      }
    }
  }

  cout << ans;
}