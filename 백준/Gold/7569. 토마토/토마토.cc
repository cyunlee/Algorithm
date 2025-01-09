#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dz[2] = {-1, 1};
int board[102][102][102]; // n, m, h
int dist[102][102][102];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int m, n, h;
	cin >> m >> n >> h; //m(가로칸 수), n(세로칸 수) -> n개의 행 * m개의 열
	
	//토마토 입력받기
	for(int i=0; i<h; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				cin >> board[j][k][i];
				
				if(board[j][k][i]==0) dist[j][k][i]=-1;
			}
		}
	}
	
	//시작점 찾기
	queue<tuple<int, int, int>> Q;
	
	for(int i=0; i<h; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				if(board[j][k][i]==1) {
					tuple<int, int, int> t = make_tuple(j, k, i);
					Q.push(t);
				}
			}
		}
	}
	
	int days = 0;
	
	while(!Q.empty()){
		tuple<int, int, int> cur = Q.front(); Q.pop();
		
		for(int dir=0; dir<4; dir++){
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nz = get<2>(cur);
			
			if(nx<0 || nx>=n || ny<0 || ny >=m) continue;
			if(dist[nx][ny][nz]>=0 || board[nx][ny][nz]!=0) continue;
			
			dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			
			days = max(days, dist[nx][ny][nz]);
			tuple<int, int, int> nt = make_tuple(nx, ny, nz);
			Q.push(nt);	
		}
		
		for(int hei=0; hei<2; hei++){
			int nx = get<0>(cur);
			int ny = get<1>(cur);
			int nz = get<2>(cur) + dz[hei];
			
			if(nz<0 || nz>=h) continue;
			if(dist[nx][ny][nz]>=0 || board[nx][ny][nz]!=0) continue ;
			
			dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			
			days = max(days, dist[nx][ny][nz]);
			tuple<int, int, int> nt = make_tuple(nx, ny, nz);
			Q.push(nt);	
		}
	}

	for(int i=0; i<h; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<m; k++){
				if(dist[j][k][i]==-1) {
					cout << "-1";
					return 0;
				}
			}
		}
	}
	
	cout << days << '\n';
	
	return 0;
}