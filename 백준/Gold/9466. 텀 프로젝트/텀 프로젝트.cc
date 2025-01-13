#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int state[100005];
const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x){
  int cur = x;

  while(true){
    state[cur] = x; //시작점 저장
    cur = arr[cur]; //다음 노드

    if(state[cur]==x){
      while(state[cur]!=CYCLE_IN){
        state[cur] = CYCLE_IN;
        cur = arr[cur];
      }
      return;
    }
    if(state[cur]!=NOT_VISITED) return;
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--){ //TC
    int n;
    cin >> n;

    fill(state+1, state+n+1, NOT_VISITED);

    for(int i=1; i<=n; i++){
      cin >> arr[i]; //각 학생이 가리키는 학생 입력
    }

    for(int i=1; i<=n; i++){
      if(state[i] == NOT_VISITED) run(i);
    }

    int cnt = 0;
    for(int i=1; i<=n; i++){
      if(state[i]!=CYCLE_IN) cnt++;
    }

    cout << cnt << '\n';
  }
}