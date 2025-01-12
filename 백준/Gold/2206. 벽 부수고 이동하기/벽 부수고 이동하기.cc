#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[1000][1000];
int dist[1000][1000][2];
int n, m;

bool OOB(int x, int y) {
	return x<0 || x>=n || y<0 || y>=m;
}

int main(void) {
	cin >> n >> m;
	
	//맵 입력
	for(int i=0; i<n; i++){
		string str;
		cin >> str;
		for(int j=0; j<m; j++){
			board[i][j] = str[j];
			dist[i][j][0] = dist[i][j][1] = -1; //0 - brokenX, 1 - brokenO
		}
	}
	
	dist[0][0][0] = 1;
	
	queue<tuple<int, int, int>> Q;
	tuple<int, int, int> t = make_tuple(0, 0, 0);
	Q.push(t);
	
	while(!Q.empty()){
		auto cur = Q.front();
		Q.pop();
		
		int x = get<0>(cur);
		int y = get<1>(cur);
		int crash = get<2>(cur);
		
		for(int dir=0; dir<4; dir++){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			
			if(OOB(nx, ny)) continue;

			//길을 만났을 때, 아직 그 길을 지나가지 않은 경우
			if(board[nx][ny]=='0' && dist[nx][ny][crash]==-1){
				dist[nx][ny][crash] = dist[x][y][crash] + 1;
				tuple<int, int, int> nt = make_tuple(nx, ny, crash);
				Q.push(nt);
			}
			
			//이전까지 벽을 부순적이 없고, 이번에 벽을 부수는 경우
			if(board[nx][ny]=='1' && crash==0 && dist[nx][ny][1]== -1){
				dist[nx][ny][1] = dist[x][y][0] + 1;
				tuple<int, int, int> nt = make_tuple(nx, ny, 1);
				Q.push(nt);
			}
		}
	}
		
	if(dist[n-1][m-1][0]==-1 && dist[n-1][m-1][1]==-1) cout << "-1";
	else if(dist[n-1][m-1][0]==-1) cout << dist[n-1][m-1][1];
	else if(dist[n-1][m-1][1]==-1) cout << dist[n-1][m-1][0];
	else cout << min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
}