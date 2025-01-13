#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i=0; i<n; i++){
    int arr_num;
    cin >> arr_num;

    v.push_back(arr_num);
  }

  int m;
  cin >> m;

  sort(v.begin(), v.end());

  while(m--){
    int num;
    cin >> num;

    cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << " ";
  }
}