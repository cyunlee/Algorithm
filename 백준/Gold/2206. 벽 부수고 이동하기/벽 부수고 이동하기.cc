#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[1002][1002];
int dist[1002][1002][2];
int n, m;

bool OOB(int x, int y){
	return x<0 || x>=n || y<0 || y>=m;
}

int bfs() {
	queue<tuple<int, int, int>> q;
	q.push({0, 0, 0});
	dist[0][0][0] = 0;
	
	while(!q.empty()){
		int x, y, crash;
		tie(x, y, crash) = q.front();
		if(x==n-1 && y==m-1) return dist[x][y][crash] + 1;
		q.pop();
		
		for(int dir=0; dir<4; dir++){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			
			if(OOB(nx, ny)) continue;
			
			int nextdist = dist[x][y][crash] + 1;
			
			//길을 만났을 때
			if(board[nx][ny]=='0' && dist[nx][ny][crash]==-1){
				dist[nx][ny][crash] = nextdist;
				q.push({nx, ny, crash});
			}
			
			//벽을 만났고, '이전에' 벽을 부순 경우
			if(board[nx][ny]=='1' && crash==1) continue;
			
			//벽을 만났고, '이번에' 벽을 부수는 경우
			if(board[nx][ny]=='1' && crash==0 && dist[nx][ny][1]==-1){
				dist[nx][ny][1] = nextdist;
				q.push({nx, ny, 1});
			}
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	//맵 입력받기
	for(int i=0; i<n; i++){
		string str;
		cin >> str;
		for(int j=0; j<m; j++){
			board[i][j] = str[j];
			dist[i][j][0] = dist[i][j][1] = -1;
		}
	}
	
	cout << bfs();
}