#include<bits/stdc++.h>
using namespace std;

int T;

bool isUsable(char c){
  if(isdigit(c) || isalpha(c)) return true;
  return false;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  string bufferflush;
  getline(cin, bufferflush);

  for(int i=0; i<T; i++){
    string pwd;
    string ans;
    getline(cin, pwd);

    list<char> L;
    auto cursor = L.begin();

    for(char x : pwd){
      if(x=='<' && cursor!=L.begin()) {
        cursor--;
      }
      else if(isUsable(x)){
        L.insert(cursor, x);
      }
      else if(x=='>' && cursor!=L.end()){
        cursor++;
      }
      else if(x=='-' && cursor!=L.begin()){
        cursor = L.erase(prev(cursor));
      }
    }

    for(auto i : L) cout << i;
    cout << '\n';
  }
}