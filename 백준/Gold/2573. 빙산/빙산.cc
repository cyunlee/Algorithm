#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[301][301], temp[301][301];
int n, m;

//두 덩어리로 분리되는 최초의 시간?

bool OOB(int x, int y){
  return x<0 || x>=n || y<0 || y>=m;
}

int one_year() {
  int area_sum = 0;
  queue<pair<int, int>> q;
  bool vis[301][301] = {0};
  memcpy(temp, board, sizeof(board));

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){

      if(board[i][j]>0 && vis[i][j]!=1) {
        q.push({i, j});
        area_sum++;
        vis[i][j]=1;
      }

      while(!q.empty()){
        auto cur = q.front();
        q.pop();

        int sum = 0; //바닷물과 접해있는 곳의 개수

        for(int dir=0; dir<4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if(OOB(nx, ny)) continue;
          if(board[nx][ny]==0) sum++;
          if(board[nx][ny]>0 && vis[nx][ny]==0) {
            q.push({nx, ny});
            vis[nx][ny]=1;
          }
        }

        temp[cur.X][cur.Y] -= sum;
        if(temp[cur.X][cur.Y]<=0) temp[cur.X][cur.Y]=0;
      }
    }
  }
  memcpy(board, temp, sizeof(temp));
  return area_sum;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> board[i][j];
    }
  }

  int year = 0;
  while(true){
    int chunks = one_year();
    if(chunks>=2){
      cout << year << "\n";
      break;
    }else if(chunks==0){
      cout << 0 << "\n";
      break;
    }
    year++;
  }
}