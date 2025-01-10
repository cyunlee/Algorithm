#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[102][102];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  // 높이정보 입력 -> 비의 양에 따라 TC 달라짐
  int min_rain = 0;
  int max_rain = 0;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> board[i][j];

      min_rain = min(min_rain, board[i][j]);
      max_rain = max(max_rain, board[i][j]);
    }
  }

  int max_num = 0;

  //안전지역을 1, 잠긴 지역을 0
  for(int rain=min_rain; rain<=max_rain; rain++){
    int new_board[n][n] = {};
    bool vis[n][n] = {};

    //지역 구분
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(board[i][j]>rain) new_board[i][j] = 1;
      }
    }
    queue<pair<int, int>> Q;

    //시작점 개수
    int num = 0;

    //시작점 찾기
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(vis[i][j]==1||new_board[i][j]==0) continue;
        vis[i][j] = 1;
        num++;
        Q.push({i, j});

        while(!Q.empty()){
          pair<int, int> cur = Q.front();
          Q.pop();

          for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(vis[nx][ny]==1 || new_board[nx][ny]==0) continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny});
          }
        }
      }
    }

    max_num = max(max_num, num);
  }
  cout << max_num;
}