#include <bits/stdc++.h>
using namespace std;
int horse_dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int horse_dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int monkey_dx[4] = {1, 0, -1, 0};
int monkey_dy[4] = {0, 1, 0, -1};
int k, w, h; //h개의 행 * w개의 열

int board[201][201];
int dist[201][201][31]; //몇번 움직였는지 나타내는 상태 표시

queue<tuple<int, int, int>> Q;

bool OOB(int x, int y){
  return x<0 || x>=h || y<0 || y>=w;
}

void move_like_horse(int x, int y, int moves){
  for(int dir=0; dir<8; dir++){
    int nx = x + horse_dx[dir];
    int ny = y + horse_dy[dir];

    if(OOB(nx, ny) || board[nx][ny]==1) continue;
    if(moves >= k) return;
    if(dist[nx][ny][moves+1]!=-1) continue;

    dist[nx][ny][moves+1] = dist[x][y][moves] + 1;
    Q.push({nx, ny, moves+1});
  }
}

void move_like_monkey(int x, int y, int moves){
  for(int dir=0; dir<4; dir++){
    int nx = x + monkey_dx[dir];
    int ny = y + monkey_dy[dir];

    if(OOB(nx, ny) || board[nx][ny]==1) continue;
    if(dist[nx][ny][moves]!=-1) continue;

    dist[nx][ny][moves] = dist[x][y][moves] + 1;
    Q.push({nx, ny, moves});
  }
}

int bfs() {
  //(0, 0) -> (h-1, w-1)
  dist[0][0][0] = 0;
  Q.push({0, 0, 0});

  while(!Q.empty()){
    int x, y, moves;
    tie(x, y, moves) = Q.front();
    if(x==h-1 && y==w-1) return dist[x][y][moves];
    Q.pop();

    move_like_horse(x, y, moves);
    move_like_monkey(x, y, moves);
  }

  return -1;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> k;
  cin >> w >> h;

  //맵 입력받기
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cin >> board[i][j];
    }
  }

  memset(dist, -1, sizeof(dist));

  cout << bfs();
}