#include <bits/stdc++.h>
using namespace std;
int dist[1000004];

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	
	fill(dist, dist+f+1, -1);
	
	queue<int> Q;
	dist[s] = 0; //시작점 위치
	Q.push(s);
	
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		
		//up
		if(cur + u <= f && dist[cur + u]==-1){
			dist[cur + u] = dist[cur] + 1;
			Q.push(cur + u);
		}
		
		//down
		if(cur - d > 0 && dist[cur - d]==-1){
			dist[cur - d] = dist[cur] + 1;
			Q.push(cur - d);
		}
	}
	
	if(dist[g]!=-1) cout << dist[g];
	else cout << "use the stairs";
}
