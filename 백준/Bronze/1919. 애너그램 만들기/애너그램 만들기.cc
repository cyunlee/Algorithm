#include<bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str1;
  string str2;

  cin >> str1 >> str2;

  int arr1[26] = {};
  int arr2[26] = {};

  for(char x : str1) {
    arr1[x - 'a']++;
  }

  for(char y : str2){
    arr2[y - 'a']++;
  }

  int cnt = 0;

  for(int i=0; i<26; i++){
    if(arr1[i]==arr2[i]) continue;
    if(arr1[i]==0 && arr2[i]!=0) cnt = cnt + arr2[i];
    if(arr1[i]!=0 && arr2[i]==0) cnt = cnt + arr1[i];
    if(arr1[i]!=0 && arr2[i]!=0) cnt = cnt + max(arr1[i], arr2[i]) - min(arr1[i], arr2[i]);
  }

  cout << cnt;
}