#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dist[102][102];
int board[102][102];
int n, m;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	//미로 입력받기
	for(int i=0; i<n; i++){
		string row;
		cin >> row;
		
		for(int j=0; j<m; j++){
			board[i][j] = row[j];
		}
	}
	
	//dist 배열을 -1로 초기화
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			dist[i][j] = -1; 
		}
	}
	
	queue<pair<int, int>> Q;

	dist[0][0] = 1; //시작점
	Q.push({0, 0});
	
	while(!Q.empty()){
		pair<int, int> cur = Q.front();
		Q.pop();
		
		for(int dir=0; dir<4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			
			if(nx < 0 || nx >= n || ny < 0 || ny>=m) continue;
			if(dist[nx][ny] != -1 || board[nx][ny]=='0') continue;
			
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({nx, ny});
		}
	}
	
	cout << dist[n-1][m-1];
}