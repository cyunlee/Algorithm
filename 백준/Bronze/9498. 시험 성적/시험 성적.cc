#include<bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int score;
  cin >> score;

  if(90 <= score && score <= 100) cout << "A" << '\n';
  else if(80 <= score) cout << "B" << '\n';
  else if(70 <= score) cout << "C" << '\n';
  else if(60 <= score) cout << "D" << '\n';
  else cout << "F" << '\n';
}