#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> v;

  for(int i=0; i<9; i++){
    int number;
    cin >> number;
    v.push_back(number);
  }

  auto maxnum = *max_element(v.begin(), v.end());
  auto maxidx = max_element(v.begin(), v.end()) - v.begin();

  cout << maxnum << '\n';
  cout << maxidx + 1;
}