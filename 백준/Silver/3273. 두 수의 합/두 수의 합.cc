#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int occur[2000004];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x, ans = 0;

  cin >> n;

  for(int i=0; i<n; i++){
    int num;
    cin >> num;
    v.push_back(num);
  }

  cin >> x;

  for(int i=0; i<n; i++){
    occur[v[i]] = 1;
  }

  for(int i=0; i<n; i++){
    if(x-v[i] > 0 && occur[x-v[i]]){
      ans++;
    }
  }

  cout << ans / 2;
}