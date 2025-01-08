#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[1002][1002];
int fire_time[1002][1002];
int jihun_time[1002][1002];
int R, C;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> R >> C;
	
	queue<pair<int, int>> fireQ;
	queue<pair<int, int>> jihunQ;
	
	//미로 입력
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin >> board[i][j];
			
			if(board[i][j]=='F'){
				fire_time[i][j] = 0;
				fireQ.push({i, j});
			}else if(board[i][j]=='J'){
				jihun_time[i][j] = 0;
				jihunQ.push({i, j});
			}else if(board[i][j] == '.'){
				fire_time[i][j] = -1; //갈 수 있는 길 초기값 세팅
				jihun_time[i][j] = -1;
			}
		}
	}
	
	//불 BFS
	while(!fireQ.empty()){
		pair<int, int> cur = fireQ.front();
		fireQ.pop();
		
		for(int dir=0; dir<4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if(nx<0 || nx>=R || ny<0 || ny>=C) continue;
			if(fire_time[nx][ny]!=-1 || board[nx][ny]!='.') continue;
			
			fire_time[nx][ny] = fire_time[cur.X][cur.Y] + 1;
			fireQ.push({nx, ny});
		}
	}
	
	//지훈 BFS
	while(!jihunQ.empty()){
		pair<int, int> cur = jihunQ.front();
		jihunQ.pop();
		
		for(int dir=0; dir<4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if(nx < 0 || nx >= R || ny < 0 || ny >= C) {
				cout << jihun_time[cur.X][cur.Y] + 1; 
				return 0;
			}
			if(jihun_time[nx][ny]!=-1 || board[nx][ny]!='.') continue;
			if(fire_time[nx][ny]!=-1 && jihun_time[cur.X][cur.Y] + 1 >= fire_time[nx][ny]) continue;
			
			jihun_time[nx][ny] = jihun_time[cur.X][cur.Y] + 1;
			jihunQ.push({nx, ny});
		}
	}
	cout << "IMPOSSIBLE";
}
