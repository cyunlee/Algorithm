#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[102][102];
int vis[102][102];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m, n, k;
  cin >> m >> n >> k; // m개의 행 * n개의 열

  //좌표 입력
  //직사각형은 1으로 배열에 넣기
  for(int i=0; i<k; i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for(int t=x1; t<x2; t++){
      for(int p=y1; p<y2; p++){
        board[m-p-1][t] = 1;
      }
    }
  }

  //시작점 찾기
  queue<pair<int, int>> Q;

  int num = 0; //영역 개수
  vector<int> areas;

  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      if(vis[i][j]==1 || board[i][j]==1) continue;
      vis[i][j] = 1;
      Q.push({i, j});
      num++;

      int area = 0;

      while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        area++;

        for(int dir=0; dir<4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
          if(vis[nx][ny]==1 || board[nx][ny]==1) continue;
          vis[nx][ny] = 1;
          Q.push({nx, ny});
        }
      }

      areas.push_back(area);
    }
  }

  sort(areas.begin(), areas.end());

  cout << num << '\n';
  for(int area : areas) cout << area << " ";
}