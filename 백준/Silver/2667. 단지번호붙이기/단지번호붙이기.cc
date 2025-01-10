#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[30][30];
bool vis[30][30];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n; //한 변의 길이

  //정보 입력받기
  for(int i=0; i<n; i++) {
    string str;
    cin >> str;
    for(int j=0; j<n; j++){
      board[i][j] = str[j];
    }
  }

  queue<pair<int, int>> Q;

  int num = 0; //단지 수
  vector<int> areas;

  //시작점 찾기
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(vis[i][j]==1 || board[i][j]=='0') continue;

      vis[i][j] = 1;
      Q.push({i, j});
      num++;

      int area = 0; //가구 수

      while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        area++;

        for(int dir=0; dir<4; dir++){
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];

          if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
          if(vis[nx][ny]==1 || board[nx][ny]=='0') continue;

          vis[nx][ny] = 1;
          Q.push({nx, ny});
        }
      }

      areas.push_back(area);

    }
  }
  cout << num << '\n';
  sort(areas.begin(), areas.end());
  for(int area : areas) cout << area << '\n';
}