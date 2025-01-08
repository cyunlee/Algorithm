#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[502][502];
bool vis[502][502];
int n, m;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	//그림 정보 입력
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> board[i][j];
		}
	}
	
	int num = 0;
	int mx = 0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			//시작점 찾기
			if(vis[i][j]==1 || board[i][j]==0) continue;
			
			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({i, j});
			num++; //시작점 개수 = 그림 개수
			
			int area = 0; //그림의 넓이
			//하나의 BFS 당 하나의 큐가 존재
			
			while(!Q.empty()){
				pair<int, int> cur = Q.front();
				Q.pop();
				area++;
				
				for(int dir=0; dir<4; dir++){
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					
					if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
					if(vis[nx][ny]==1 || board[nx][ny]==0) continue;
					
					vis[nx][ny] = 1;
					Q.push({nx,ny});
				}
			}
			
			mx = max(area, mx);
		}
	}
	cout << num << '\n' << mx;
}