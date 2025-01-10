#include <bits/stdc++.h>
using namespace std;
string str;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(true){
    getline(cin, str, '.');
    string bufferflush;
    getline(cin, bufferflush);

    bool isBalanced = false;

    if(str=="") break;

    stack<char> S;

    for(char x : str) {
      if(x == '('||x == '[') S.push(x);
      else if(x == ')'){
        if(!S.empty() && S.top() == '(') {
          S.pop();
        }else S.push(x);
      }
      else if(x == ']'){
        if(!S.empty() && S.top() == '[') {
          S.pop();
        }else S.push(x);
      }
    }

    if(S.empty()) isBalanced = true;
    else isBalanced = false;

    if(isBalanced){
      cout << "yes" << '\n';
    }else {
      cout << "no" << '\n';
    }
  }
}