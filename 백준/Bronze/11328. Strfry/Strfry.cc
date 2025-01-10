#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for(int i=0; i<N; i++){
    string str1;
    string str2;

    cin >> str1 >> str2;

    int arr1[26] = {};
    int arr2[26] = {};
    int cnt = 0;

    for(char x : str1){
      arr1[x-'a']++;
    }

    for(char y : str2){
      arr2[y-'a']++;
    }

    for(int i=0; i<26; i++){
      if(arr1[i]==arr2[i]) cnt++;
    }

    if(cnt == 26){
      cout << "Possible" << '\n';
    }else {
      cout << "Impossible" << '\n';
    }
  }
}