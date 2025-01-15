#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  cin >> a >> b;
  
  double new_a = (double)a;
  double new_b = (double)b;

  cout << fixed << setprecision(9) << new_a / new_b;
}