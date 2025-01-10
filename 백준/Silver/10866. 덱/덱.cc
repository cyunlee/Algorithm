#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  deque<int> DQ;

  for(int i=0; i<N; i++){
    string cmd;
    cin >> cmd;

    if(cmd == "push_front"){
      int val;
      cin >> val;
      DQ.push_front(val);
    }else if(cmd == "push_back"){
      int val;
      cin >> val;
      DQ.push_back(val);
    }else if(cmd == "pop_front"){
      if(DQ.empty()){
        cout << "-1" << '\n';
      }else{
        cout << DQ.front() << '\n';
        DQ.pop_front();
      }
    }else if(cmd == "pop_back"){
      if(DQ.empty()){
        cout << "-1" << '\n';
      }else{
        cout << DQ.back() << '\n';
        DQ.pop_back();
      }
    }else if(cmd == "size"){
      cout << DQ.size() << '\n';
    }else if(cmd == "empty"){
      if(DQ.empty()) cout << "1" << '\n';
      else cout << "0" << '\n';
    }else if(cmd == "front"){
      if(DQ.empty()) cout << "-1" << '\n';
      else cout << DQ.front() << '\n';
    }else if(cmd == "back"){
      if(DQ.empty()) cout << "-1" << '\n';
      else cout << DQ.back() << '\n';
    }
  }
}