#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  //TC 2개
  char board1[102][102] = {};
  bool vis1[102][102] = {};

  char board2[102][102] = {};
  bool vis2[102][102] = {};

  //보드 채우기
  for(int i=0; i<n; i++){
    string str;
    cin >> str;
    for(int j=0; j<n; j++){
      board1[i][j] = str[j];
    }

    for(int j=0; j<n; j++){
      if(str[j]=='R') str[j]='G';
      board2[i][j] = str[j];
    }
  }

  //시작점 찾기 - 정상
  int num1 = 0; //구역의 수 - 정상
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(vis1[i][j]==1) continue;

      queue<pair<int, int>> Q1;
      vis1[i][j] = 1;
      Q1.push({i, j});
      num1++;

      while(!Q1.empty()){
        auto cur = Q1.front(); Q1.pop();

        for(int dir=0; dir<4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
          if(vis1[nx][ny]==1||board1[nx][ny]!=board1[cur.X][cur.Y]) continue;

          vis1[nx][ny] = 1;
          Q1.push({nx, ny});
        }
      }
    }
  }

  //시작점 찾기 - 색약
  int num2 = 0; //구역의 수 - 색약
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(vis2[i][j]==1) continue;

      queue<pair<int, int>> Q2;
      vis2[i][j] = 1;
      Q2.push({i, j});
      num2++;

      while(!Q2.empty()){
        auto cur = Q2.front(); Q2.pop();

        for(int dir=0; dir<4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
          if(vis2[nx][ny]==1||board2[nx][ny]!=board2[cur.X][cur.Y]) continue;

          vis2[nx][ny] = 1;
          Q2.push({nx, ny});
        }
      }
    }
  }

  cout << num1 << " " << num2;
}