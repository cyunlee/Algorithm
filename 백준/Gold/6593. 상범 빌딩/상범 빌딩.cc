#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dz[2] = {1, -1};
char board[31][31][31];
int dist[31][31][31];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int l, r, c;
	
	while(true){
		board[31][31][31] = {};
		dist[31][31][31] = {};
		
		cin >> l >> r >> c;
		
		if(l==0 && r==0 && c==0) return 0;
		
		queue<tuple<int, int, int>> Q;
		
		int el, er, ec;
		
		//입력 받기
		for(int i=0; i<l; i++){
			for(int j=0; j<r; j++){
				string str;
				cin >> str;
				for(int k=0; k<c; k++){
					dist[j][k][i] = -1;
					
					//시작점 찾기
					if(str[k] == 'S') { 
						dist[j][k][i] = 0;
						tuple<int, int, int> t = make_tuple(j, k, i);
						Q.push(t);
					}
					//E의 좌표 찾기
					if(str[k] == 'E'){
						el = i;
						er = j;
						ec = k;
					}
					
					board[j][k][i] = str[k];
				}
			}
		}
		
		//BFS
		for(int i=0; i<l; i++){
			for(int j=0; j<r; j++){
				for(int k=0; k<c; k++){
					while(!Q.empty()){
						tuple<int, int, int> cur = Q.front();
						Q.pop();
						
						for(int dir=0; dir<4; dir++){
							int nx = get<0>(cur) + dx[dir];
							int ny = get<1>(cur) + dy[dir];
							int nz = get<2>(cur);
							
							if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
							if(dist[nx][ny][nz]!=-1 || board[nx][ny][nz]=='#') continue;
							
							dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
							tuple<int, int, int> nt = make_tuple(nx, ny, nz);
							Q.push(nt);
						}
						
						for(int dir=0; dir<2; dir++){
							int nx = get<0>(cur);
							int ny = get<1>(cur);
							int nz = get<2>(cur) + dz[dir];
							
							if(nx<0 || nx>=r || ny<0 || ny>=c) continue;
							if(dist[nx][ny][nz]!=-1 || board[nx][ny][nz]=='#') continue;
							
							dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
							tuple<int, int, int> nt = make_tuple(nx, ny, nz);
							Q.push(nt);
						}
					}
				}
			}
		}
		
		if(dist[er][ec][el]==-1) cout << "Trapped!\n";
		else cout << "Escaped in " << dist[er][ec][el] << " minute(s).\n";	
	}
}