#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[502][502];
bool vis[502][502];
int n, m;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  //그림 정보 입력
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> board[i][j];
    }
  }

  int num = 0; //그림의 개수
  int mx = 0; //그림 넓이의 최댓값

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(vis[i][j]==1 || board[i][j]==0) continue;
      vis[i][j] = 1;
      num++;

      queue<pair<int, int>> Q; //시작점마다 큐가 하나씩
      Q.push({i, j});

      int area=0;

      while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        area++;

        for(int dir=0; dir<4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
          if(vis[nx][ny]==1||board[nx][ny]==0) continue;

          vis[nx][ny] = 1;
          Q.push({nx, ny});
        }
      }

      mx = max(mx, area);
    }
  }
  cout << num << '\n' << mx;
}