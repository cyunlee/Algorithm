#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[1002][1002];
int dist1[1002][1002];//불
int dist2[1002][1002]; //상근

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t; //TC

  for(int i=0; i<t; i++){

    int w, h;
    cin >> w >> h; //가로 - w, 세로 - h -> h개의 행 * w개의 열

    queue<pair<int, int>> Q1; //불
    queue<pair<int, int>> Q2; //상근

    //board, dist 초기화
    for(int j=0; j<1002; j++){
      for(int k=0; k<1002; k++){
        board[j][k] = ' ';
        dist1[j][k] = -1;
        dist2[j][k] = -1;
      }
    }

    //지도 입력
    for(int j=0; j<h; j++){
      for(int k=0; k<w; k++){
        cin >> board[j][k];

        if(board[j][k]=='*'){
          dist1[j][k] = 0;
          Q1.push({j, k});
        }else if(board[j][k]=='@'){
          dist2[j][k] = 0;
          Q2.push({j, k});
        }else if(board[j][k]=='.'){
          dist1[j][k] = -1;
          dist2[j][k] = -1;
        }
      }
    }

    //불 BFS
    while(!Q1.empty()){
      pair<int, int> cur = Q1.front(); Q1.pop();

      for(int dir=0; dir<4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];

        if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
        if(dist1[nx][ny]!=-1 || board[nx][ny]=='#') continue;

        dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
        Q1.push({nx, ny});
      }
    }

    //상근 BFS
    bool escaped = false;
    while(!Q2.empty() && escaped==false){
      pair<int, int> cur = Q2.front(); Q2.pop();

      for(int dir=0; dir<4; dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];

        if(nx<0 || nx>=h || ny<0 || ny>=w) {
          escaped = true;
          cout << dist2[cur.X][cur.Y] + 1 << '\n';
          break;
        }

        if(dist2[nx][ny]!=-1 || board[nx][ny]=='#') continue;
        if(dist1[nx][ny]!=-1 && dist2[cur.X][cur.Y] + 1 >= dist1[nx][ny]) continue;


        dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
        Q2.push({nx, ny});
      }
    }

    if(escaped==false) cout << "IMPOSSIBLE" << '\n';
  }
  return 0;
}