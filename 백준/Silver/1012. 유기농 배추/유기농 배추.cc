#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int T;
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  for(int i=0; i<T; i++){
    int board[2502][2502] = {};
    bool vis[2502][2502] = {};

    int m, n, k;//가로 길이: m, 세로 길이: n -> n개의 행 * m개의 열
    cin >> m >> n >> k;

    //배추 심기
    for(int i=0; i<k; i++){
      int x, y; //문제에서 x가 열, y가 행
      cin >> y >> x;
      board[x][y] = 1;
    }

    int num = 0; //배추흰지렁이 수 = 시작점의 개수

    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(vis[i][j]==1 || board[i][j]==0) continue;
        vis[i][j] = 1;
        num++;

        queue<pair<int, int>> Q;
        Q.push({i, j});

        while(!Q.empty()){
          pair<int, int> cur = Q.front(); Q.pop();

          for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(vis[nx][ny]==1 || board[nx][ny]==0) continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny});
          }
        }
      }
    }
    cout << num << '\n';
  }
}