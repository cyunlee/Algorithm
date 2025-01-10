#include<bits/stdc++.h>
using namespace std;

int N, K, S, Y;

int girls[6] = {};
int boys[6] = {};

int gsum, bsum;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  for(int i=0; i<N; i++){
    cin >> S >> Y;

    if(S==0){
      girls[Y-1]++;
    }else if(S==1){
      boys[Y-1]++;
    }
  }
  //index = 학년 - 1

  for(int i=0; i<6; i++){
    int room = 0;
    int mok = girls[i] / K;
    int rest = girls[i] % K;
    if(rest>0) {
      room = mok + 1;
    }else {
      room = mok;
    }
    gsum += room;
  }

  for(int i=0; i<6; i++){
    int room = 0;
    int mok = boys[i] / K;
    int rest = boys[i] % K;
    if(rest>0) {
      room = mok + 1;
    }else {
      room = mok;
    }
    bsum += room;
  }

  cout << gsum + bsum;
}