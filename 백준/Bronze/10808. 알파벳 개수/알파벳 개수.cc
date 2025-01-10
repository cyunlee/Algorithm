#include<bits/stdc++.h>
using namespace std;
string s;
int ret[26];

int main() {
  cin >> s;

  for(char x : s) {
    int idx = x - 97;
    ret[idx]++;
  }

  for(int num : ret) {
    cout << num << ' ';
  }

  return 0;
}